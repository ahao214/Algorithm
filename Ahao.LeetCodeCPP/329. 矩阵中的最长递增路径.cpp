#include<vector>

using namespace std;

/*
329. 矩阵中的最长递增路径

给定一个 m x n 整数矩阵 matrix ，找出其中最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线 方向上移动或移动到 边界外（即不允许环绕）。
*/
class Solution {
public:
	vector<vector<int>> f;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
	int n, m;
	int dp(int x, int y, vector<vector<int>>& matrix)
	{
		if (f[x][y] != -1) return f[x][y];
		f[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b<m && matrix[a][b] > matrix[x][y])
			{
				f[x][y] = max(f[x][y], dp(a, b, matrix) + 1);
			}
		}
		return f[x][y];
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;
		n = matrix.size(), m = matrix[0].size();
		f = vector<vector<int>>(n, vector<int>(m, -1));
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				res = max(res, dp(i, j, matrix));
			}
		}
		return res;
	}
};




class Solution {
	int m, n;
	int memo[200][200];
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		m = matrix.size();
		n = matrix[0].size();

		int res = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				res = max(res, dfs(matrix, i, j));
		}
		return res;
	}

	int dfs(vector<vector<int>>& matrix, int i, int j)
	{
		if (memo[i][j] != 0)
			return memo[i][j];

		vector<pair<int, int>> dir{ {1,0},{-1,0},{0,1},{0,-1} };
		int res = 0;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dir[k].first;
			int y = j + dir[k].second;
			if (x < 0 || x >= m || y < 0 || y >= n) continue;
			if (matrix[x][y] <= matrix[i][j])continue;
			res = max(res, dfs(matrix, x, y));
		}
		memo[i][j] = 1 + res;
		return 1 + res;
	}
};