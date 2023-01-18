#include<vector>
#include<queue>

using namespace std;



/*
1765. 地图中的最高点
给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。
*/
#define x first
#define y second
class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		typedef pair<int, int> PII;
		const int INF = 1e8;

		int n = isWater.size(), m = isWater[0].size();
		vector<vector<int>> d(n, vector<int>(m, INF));
		queue<PII> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (isWater[i][j])
				{
					d[i][j] = 0;
					q.push({ i,j });
				}
			}
		}

		int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
		while (q.size())
		{
			auto t = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int x = t.x + dx[i], y = t.y + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if (d[x][y] > d[t.x][t.y] + 1)
				{
					d[x][y] = d[t.x][t.y] + 1;
					q.push({ x,y });
				}
			}
		}
		return d;
	}
};




/*
1765. 地图中的最高点

给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。
*/
class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int m = isWater.size(), n = isWater[0].size();
		queue<pair<int, int>> q;
		vector<vector<int>> vis(m, vector<int>(n)), dis(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				//水域格子，高度为0，作为BFS的初始节点
				if (isWater[i][j] == 1) {
					q.push({ i,j });
					dis[i][j] = 0;
					vis[i][j] = 1;
				}
			}
		}
		const vector<vector<int>> dirs = { {-1,0},{1,0},{0,1},{0,-1} };
		while (!q.empty()) {
			auto [cx, cy] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int x = cx + dirs[i][0], y = cy + dirs[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n)continue;
				if (!vis[x][y] && isWater[x][y] == 0) {
					dis[x][y] = dis[cx][cy] + 1;
					q.push({ x,y });
					vis[x][y] = 1;
				}
			}
		}
		return dis;
	}
};