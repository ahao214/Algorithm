#include<vector>
#include <deque>

using namespace std;



/*
1368. 使网格图至少有一条有效路径的最小代价
给你一个 m x n 的网格图 grid 。
grid 中每个格子都有一个数字，
对应着从该格子出发下一步走的方向。
grid[i][j] 中的数字可能为以下几种情况：
数字1表示下一步往右走，也就是你会从 grid[i][j] 走到 grid[i][j + 1]
数字2表示下一步往左走，也就是你会从 grid[i][j] 走到 grid[i][j - 1]
数字3表示下一步往下走，也就是你会从 grid[i][j] 走到 grid[i + 1][j]
数字4表示下一步往上走，也就是你会从 grid[i][j] 走到 grid[i - 1][j]
注意网格图中可能会有 无效数字 ，因为它们可能指向 grid 以外的区域。

一开始，你会从最左上角的格子 (0,0) 出发。
我们定义一条 有效路径 为从格子 (0,0) 出发，
每一步都顺着数字对应方向走，最终在最右下角的格子 (m - 1, n - 1)
结束的路径。有效路径 不需要是最短路径 。

你可以花费 cost = 1 的代价修改一个格子中的数字，
但每个格子中的数字 只能修改一次 。

请你返回让网格图至少有一条有效路径的最小代价。
*/
class Solution {
public:
	int minCost(vector<vector<int>>& grid) {
		typedef pair<int, int> PII;
		const int INF = 0x3f3f3f3f;
		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> dist(n, vector<int>(m, INF));
		vector<vector<bool>> st(n, vector<bool>(m));

		int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

		deque<PII> q;
		q.push_back({ 0,0 });
		dist[0][0] = 0;

		while (q.size())
		{
			auto t = q.front();
			q.pop_front();

			if (st[t.first][t.second]) continue;
			st[t.first][t.second] = true;

			for (int i = 0; i < 4; i++)
			{
				int x = t.first + dx[i], y = t.second + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m)
					continue;

				int w = grid[t.first][t.second] - 1 != i;
				if (dist[x][y] > dist[t.first][t.second] + w)
				{
					dist[x][y] = dist[t.first][t.second] + w;
					if (w == 0) q.push_front({ x,y });
					else q.push_back({ x,y });
				}
			}
		}
		return dist[n - 1][m - 1];
	}
};
