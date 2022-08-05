#include<vector>
#include<queue>

using namespace std;


/*
1926. 迷宫中离入口最近的出口
给你一个 m x n 的迷宫矩阵 maze （下标从 0 开始），矩阵中有空格子（用 '.' 表示）和墙（用 '+' 表示）。同时给你迷宫的入口 entrance ，用 entrance = [entrancerow, entrancecol] 表示你一开始所在格子的行和列。

每一步操作，你可以往 上，下，左 或者 右 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 entrance 最近 的出口。出口 的含义是 maze 边界 上的 空格子。entrance 格子 不算 出口。

请你返回从 entrance 到最近出口的最短路径的 步数 ，如果不存在这样的路径，请你返回 -1 。
*/
#define x first
#define y second

typedef pair<int, int> PII;

class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int n = maze.size(), m = maze[0].size(), INF = 1e8;
		vector<vector<int>> dist(n, vector<int>(m, INF));
		dist[entrance[0]][entrance[1]] = 0;
		queue<PII> q;
		q.push({ entrance[0],entrance[1] });
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = t.x + dx[i], y = t.y + dy[i];
				if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.' && dist[x][y] > dist[t.x][t.y] + 1)
				{
					dist[x][y] = dist[t.x][t.y] + 1;
					if (!x || x == n - 1 || !y || y == m - 1)
						return dist[x][y];
					q.push({ x,y });
				}
			}
		}
		return -1;
	}
};


