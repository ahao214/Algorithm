#include<vector>

using namespace std;




/*
1905. 统计子岛屿
给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。

如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿 。

请你返回 grid2 中 子岛屿 的 数目 。
*/
class Solution {
public:
	int n, m;
	vector<vector<int>> g1, g2;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	bool dfs(int x, int y)
	{
		g2[x][y] = 0;
		bool res = true;
		if (!g1[x][y]) res = false;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m && g2[a][b])
			{
				if (!dfs(a, b)) res = false;
			}
		}
		return res;
	}

	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		g1 = grid1, g2 = grid2;
		n = g1.size(), m = g1[0].size();
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g2[i][j])
					if (dfs(i, j))res++;
			}
		}
		return res;
	}
};
