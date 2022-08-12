#include<vector>
#include<set>


using namespace std;




/*
1878. 矩阵中最大的三个菱形和
*/
const int N = 110;
int s1[N][N], s2[N][N];
class Solution {
public:
	vector<int> getBiggestThree(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
				s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
			}
		}

		set<int> s;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				s.insert(grid[i - 1][j - 1]);
				for (int k = 1; i - k >= 1 && i + k <= n && j - k >= 1 && j + k <= m; k++)
				{
					int a = s2[i][j - k] - s2[i - k][j];
					int b = s1[i][j + k] - s1[i - k][j];
					int c = s2[i + k][j] - s2[i][j + k];
					int d = s1[i + k][j] - s1[i][j - k];
					s.insert(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
				}
				while (s.size() > 3) s.erase(s.begin());
			}
		}
		return vector<int>(s.rbegin(), s.rend());
	}

};
