#include<vector>

using namespace std;


/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
*/
class Solution {
public:
	int n, m;
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		n = grid.size(), m = grid[0].size();
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1') {
					res++;
					dfs(grid, i, j);
				}
			}
		}
		return res;
	}

	void dfs(vector<vector<char>>& grid, int x, int y) {
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
		grid[x][y] = '0';
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '1')
				dfs(grid, a, b);
		}
	}
};