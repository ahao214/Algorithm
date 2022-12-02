using namespace std;

#include<vector>


/*
62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
*/
class Solution {
public:
	/*
	Times:O(m*n)
	Space:O(m*n)
	*/
	int uniquePaths(int m, int n) {
		vector<vector<int>> f(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}
		return f[m - 1][n - 1];
	}
};




/*
62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> f(n, vector<int>(m, 0));
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i || j)
				{
					if (i) f[i][j] += f[i - 1][j];
					if (j) f[i][j] += f[i][j - 1];
				}
			}
		}
		return f[n - 1][m - 1];
	}
};
