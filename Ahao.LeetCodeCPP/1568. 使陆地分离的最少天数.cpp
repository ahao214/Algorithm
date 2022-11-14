#include<vector>

using namespace std;



/*
1568. 使陆地分离的最少天数
给你一个由若干 0 和 1 组成的二维网格 grid ，其中 0 表示水，而 1 表示陆地。岛屿由水平方向或竖直方向上相邻的 1 （陆地）连接形成。

如果 恰好只有一座岛屿 ，则认为陆地是 连通的 ；否则，陆地就是 分离的 。

一天内，可以将任何单个陆地单元（1）更改为水单元（0）。

返回使陆地分离的最少天数。
*/
class Solution {
public:
	int n, m;
	vector<vector<bool>> st;
	vector<vector<int>> g;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	void dfs(int x, int y)
	{
		st[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && g[a][b] == 1)
				dfs(a, b);
		}
	}

	bool check() {
		int cnt = 0;
		st = vector<vector<bool>>(n, vector<bool>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!st[i][j] && g[i][j] == 1)
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		return cnt > 1 || !cnt;
	}

	int minDays(vector<vector<int>>& grid) {
		n = grid.size(), m = grid[0].size();
		g = grid;

		if (check()) return 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g[i][j])
				{
					g[i][j] = 0;
					if (check()) return 1;
					g[i][j] = 1;
				}
			}
		}
		return 2;
	}
};