#include<vector>
#include<queue>

using namespace std;


/*
1786. 从第一个节点出发到最后一个节点的受限路径数
现有一个加权无向连通图。给你一个正整数 n ，表示图中有 n 个节点，并按从 1 到 n 给节点编号；另给你一个数组 edges ，其中每个 edges[i] = [ui, vi, weighti] 表示存在一条位于节点 ui 和 vi 之间的边，这条边的权重为 weighti 。

从节点 start 出发到节点 end 的路径是一个形如 [z0, z1, z2, ..., zk] 的节点序列，满足 z0 = start 、zk = end 且在所有符合 0 <= i <= k-1 的节点 zi 和 zi+1 之间存在一条边。

路径的距离定义为这条路径上所有边的权重总和。用 distanceToLastNode(x) 表示节点 n 和 x 之间路径的最短距离。受限路径 为满足 distanceToLastNode(zi) > distanceToLastNode(zi+1) 的一条路径，其中 0 <= i <= k-1 。

返回从节点 1 出发到节点 n 的 受限路径数 。由于数字可能很大，请返回对 109 + 7 取余 的结果。
*/
using PII = pair<int, int>;
#define x first
#define y second
class Solution {
public:
	const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
	vector<vector<PII>> g;
	vector<int> dist, f;
	vector<bool> st;

	int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		g.resize(n + 1), dist.resize(n + 1, INF), f.resize(n + 1), st.resize(n + 1);
		for (auto& e : edges)
		{
			int a = e[0], b = e[1], c = e[2];
			g[a].push_back({ b,c });
			g[b].push_back({ a,c });
		}

		queue<int> q;
		q.push(n);
		dist[n] = 0;
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			st[t] = false;

			for (auto& p : g[t])
			{
				int j = p.x, w = p.y;
				if (dist[j] > dist[t] + w)
				{
					dist[j] = dist[t] + w;
					if (!st[j])
					{
						q.push(j);
						st[j] = true;
					}
				}
			}
		}
		vector<PII> vs;
		for (int i = 1; i <= n; i++)
			vs.push_back({ dist[i],i });
		sort(vs.begin(), vs.end());
		f[n] = 1;
		for (auto& v : vs)
		{
			int d = v.x, u = v.y;
			for (auto& p : g[u])
			{
				int j = p.x;
				if (d > dist[j])
					f[u] = (f[u] + f[j]) % MOD;
			}
		}
		return f[1];
	}
};

