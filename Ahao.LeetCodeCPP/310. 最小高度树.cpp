using namespace std;
#include<vector>
#include <queue>

//广度优先
class Solution {
public:
	int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj) {
		int n = adj.size();
		queue<int> qu;
		vector<bool> visit(n);
		qu.emplace(u);
		visit[u] = true;
		int node = -1;

		while (!qu.empty()) {
			int curr = qu.front();
			qu.pop();
			node = curr;
			for (auto& v : adj[curr]) {
				if (!visit[v]) {
					visit[v] = true;
					parent[v] = curr;
					qu.emplace(v);
				}
			}
		}
		return node;
	}

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) {
			return { 0 };
		}
		vector<vector<int>> adj(n);
		for (auto& edge : edges) {
			adj[edge[0]].emplace_back(edge[1]);
			adj[edge[1]].emplace_back(edge[0]);
		}

		vector<int> parent(n, -1);
		/* 找到与节点 0 最远的节点 x */
		int x = findLongestNode(0, parent, adj);
		/* 找到与节点 x 最远的节点 y */
		int y = findLongestNode(x, parent, adj);
		/* 求出节点 x 到节点 y 的路径 */
		vector<int> path;
		parent[x] = -1;
		while (y != -1) {
			path.emplace_back(y);
			y = parent[y];
		}
		int m = path.size();
		if (m % 2 == 0) {
			return { path[m / 2 - 1], path[m / 2] };
		}
		else {
			return { path[m / 2] };
		}
	}
};


//拓扑排序
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) {
			return { 0 };
		}
		vector<int> degree(n);
		vector<vector<int>> adj(n);
		for (auto& edge : edges) {
			adj[edge[0]].emplace_back(edge[1]);
			adj[edge[1]].emplace_back(edge[0]);
			degree[edge[0]]++;
			degree[edge[1]]++;
		}
		queue<int> qu;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (degree[i] == 1) {
				qu.emplace(i);
			}
		}
		int remainNodes = n;
		while (remainNodes > 2) {
			int sz = qu.size();
			remainNodes -= sz;
			for (int i = 0; i < sz; i++) {
				int curr = qu.front();
				qu.pop();
				for (auto& v : adj[curr]) {
					if (--degree[v] == 1) {
						qu.emplace(v);
					}
				}
			}
		}
		while (!qu.empty()) {
			ans.emplace_back(qu.front());
			qu.pop();
		}
		return ans;
	}
};





/*
310. 最小高度树

树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
*/
class Solution {
public:
	vector<vector<int>> g;
	vector<int> d1, d2, p1, p2, up;

	void dfs1(int u, int father)
	{
		for (int x : g[u])
		{
			if (x == father) continue;
			dfs1(x, u);
			int d = d1[x] + 1;
			if (d >= d1[u])
			{
				d2[u] = d1[u], d1[u] = d;
				p2[u] = p1[u], p1[u] = x;
			}
			else if (d > d2[u])
			{
				d2[u] = d;
				p2[u] = x;
			}
		}
	}

	void dfs2(int u, int father)
	{
		for (int x : g[u])
		{
			if (x == father) continue;
			if (p1[u] == x) up[x] = max(up[u], d2[u]) + 1;
			else up[x] = max(up[u], d1[u]) + 1;
			dfs2(x, u);
		}
	}

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		g.resize(n);
		d1 = d2 = p1 = p2 = up = vector<int>(n);
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			g[a].push_back(b), g[b].push_back(a);
		}
		dfs1(0, -1);
		dfs2(0, -1);

		int mind = n + 1;
		for (int i = 0; i < n; i++) mind = min(mind, max(up[i], d1[i]));
		vector<int> res;

		for (int i = 0; i < n; i++)
		{
			if (max(up[i], d1[i]) == mind)
				res.push_back(i);
		}
		return res;
	}
};