#include<vector>
#include <string>


using namespace std;



/*
474. һ����
*/
class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> f(m + 1, vector<int>(n + 1));
		for (auto& str : strs)
		{
			int a = 0, b = 0;
			for (auto c : str)
			{
				if (c == '0') a++;
				else b++;
			}
			for (int i = m; i >= a; i--)
			{
				for (int j = n; j >= b; j--)
				{
					f[i][j] = max(f[i][j], f[i - a][j - b] + 1);
				}
			}
		}
		return f[m][n];
	}
};