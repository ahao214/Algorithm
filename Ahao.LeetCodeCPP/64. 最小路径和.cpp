using namespace std;

#include<vector>


class Solution {
	/*
	64. 最小路径和
	给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

	说明：每次只能向下或者向右移动一步。
	*/
public:
	/*
	Times:O(m*n)
	Space:O(m*n)
	*/
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> f(m, vector<int>(n, INT_MAX));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!i && !j) f[i][j] = grid[i][j];
				else
				{
					if (i) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
					if (j) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
				}
			}
		}
		return f[m - 1][n - 1];
	}

}