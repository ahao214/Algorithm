#include<vector>

using namespace std;


/*
1377. T 秒后青蛙的位置

给你一棵由 n 个顶点组成的无向树，顶点编号从 1 到 n。青蛙从 顶点 1 开始起跳。规则如下：

在一秒内，青蛙从它所在的当前顶点跳到另一个 未访问 过的顶点（如果它们直接相连）。
青蛙无法跳回已经访问过的顶点。
如果青蛙可以跳到多个不同顶点，那么它跳到其中任意一个顶点上的机率都相同。
如果青蛙不能跳到任何未访问过的顶点上，那么它每次跳跃都会停留在原地。
无向树的边用数组 edges 描述，其中 edges[i] = [fromi, toi] 意味着存在一条直接连通 fromi 和 toi 两个顶点的边。

返回青蛙在 t 秒后位于目标顶点 target 上的概率。
*/
class Solution {
public:
	vector<vector<int>> e;
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		e = vector<vector<int>>(n + 1);

		for (auto edge : edges)
		{
			int a = edge[0], b = edge[1];
			e[a].push_back(b);
			e[b].push_back(a);
		}
		return dfs(1, -1, t, target, 1);
	}

	double dfs(int u, int father, int t, int target, double p)
	{
		if (t == 0)
		{
			if (u == target) return p;
			return 0;
		}
		int k = e[u].size();
		if (u != 1) k--;

		if (!k)
		{
			if (u == target) return p;
			return 0;
		}

		double res = 0;
		for (auto s : e[u])
		{
			if (s != father)
				res = max(res, dfs(s, u, t - 1, target, p * 1.0 / k));
		}
		return res;
	}
};


class Solution {
public:
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<vector<int>> G(n + 1);
		for (int i = 0; i < edges.size(); ++i) {
			G[edges[i][0]].push_back(edges[i][1]);
			G[edges[i][1]].push_back(edges[i][0]);
		}
		vector<bool> visited(n + 1, false);
		return dfs(G, visited, 1, t, target);
	}

	double dfs(vector<vector<int>>& G, vector<bool>& visited, int i, int t, int target) {
		int nxt = i == 1 ? G[i].size() : G[i].size() - 1;
		if (t == 0 || nxt == 0) {
			return i == target ? 1.0 : 0.0;
		}
		visited[i] = true;
		double ans = 0.0;
		for (int j : G[i]) {
			if (!visited[j]) {
				ans += dfs(G, visited, j, t - 1, target);
			}
		}
		return ans / nxt;
	}
};
