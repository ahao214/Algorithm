#include<vector>

using namespace std;


/*
1559. 二维网格图中探测环
给你一个二维字符网格数组 grid ，大小为 m x n ，你需要检查 grid 中是否存在 相同值 形成的环。

一个环是一条开始和结束于同一个格子的长度 大于等于 4 的路径。对于一个给定的格子，你可以移动到它上、下、左、右四个方向相邻的格子之一，可以移动的前提是这两个格子有 相同的值 。

同时，你也不能回到上一次移动时所在的格子。比方说，环  (1, 1) -> (1, 2) -> (1, 1) 是不合法的，因为从 (1, 2) 移动到 (1, 1) 回到了上一次移动时的格子。

如果 grid 中有相同值形成的环，请你返回 true ，否则返回 false 。
*/
class Solution {
public:
	vector<vector<char>> g;
	vector<vector<bool>> st;

	bool containsCycle(vector<vector<char>>& grid) {
		g = grid;
		st = vector<vector<bool>>(g.size(), vector<bool>(g[0].size()));
		for (int i = 0; i < g.size(); i++)
		{
			for (int j = 0; j < g[0].size(); j++)
			{
				if (!st[i][j] && dfs(i, j, -1))
					return true;
			}
		}
		return false;
	}

	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	bool dfs(int x, int y, int p)
	{
		st[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			if (i != p)
			{
				int a = x + dx[i], b = y + dy[i];
				if (a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[x][y] == g[a][b])
				{
					if (st[a][b])return true;
					if (dfs(a, b, i ^ 1)) return true;
				}
			}
		}
		return false;
	}
};

