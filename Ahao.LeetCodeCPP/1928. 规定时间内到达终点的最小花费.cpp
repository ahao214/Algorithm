#include<vector>
#include<queue>

using namespace std;


/*
1928. 规定时间内到达终点的最小花费
一个国家有 n 个城市，城市编号为 0 到 n - 1 ，题目保证 所有城市 都由双向道路 连接在一起 。道路由二维整数数组 edges 表示，其中 edges[i] = [xi, yi, timei] 表示城市 xi 和 yi 之间有一条双向道路，耗费时间为 timei 分钟。两个城市之间可能会有多条耗费时间不同的道路，但是不会有道路两头连接着同一座城市。

每次经过一个城市时，你需要付通行费。通行费用一个长度为 n 且下标从 0 开始的整数数组 passingFees 表示，其中 passingFees[j] 是你经过城市 j 需要支付的费用。

一开始，你在城市 0 ，你想要在 maxTime 分钟以内 （包含 maxTime 分钟）到达城市 n - 1 。旅行的 费用 为你经过的所有城市 通行费之和 （包括 起点和终点城市的通行费）。

给你 maxTime，edges 和 passingFees ，请你返回完成旅行的 最小费用 ，如果无法在 maxTime 分钟以内完成旅行，请你返回 -1 。
*/

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1010, M = 2010, INF = 0x3f3f3f3f;

int h[N], e[M], w[M], ne[M], idx;
int dist[N][N];
bool st[N][N];

class Solution {
public:
	void add(int a, int b, int c)
	{
		e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
	}

	int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
		int n = passingFees.size();
		memset(h, -1, sizeof h), idx = 0;
		for (auto& e : edges)
		{
			int a = e[0], b = e[1], c = e[2];
			add(a, b, c), add(b, a, c);
		}
		memset(dist, 0x3f, sizeof dist);
		dist[0][0] = passingFees[0];
		queue<PII> q;
		q.push({ 0,0 });

		while (q.size())
		{
			auto t = q.front();
			q.pop();
			st[t.x][t.y] = false;

			for (int i = h[t.x]; ~i; i = ne[i])
			{
				int x = e[i], y = t.y + w[i];
				if (y > maxTime) continue;
				if (dist[x][y] > dist[t.x][t.y] + passingFees[x])
				{
					dist[x][y] = dist[t.x][t.y] + passingFees[x];
					if (!st[x][y])
					{
						st[x][y] = true;
						q.push({ x,y });
					}
				}
			}
		}

		int res = INF;
		for (int i = 0; i <= maxTime; i++)
			res = min(res, dist[n - 1][i]);
		if (res == INF) return -1;
		return res;
	}
};
