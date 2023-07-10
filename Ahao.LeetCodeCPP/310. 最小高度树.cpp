using namespace std;
#include<vector>
#include <queue>

//�������
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
		/* �ҵ���ڵ� 0 ��Զ�Ľڵ� x */
		int x = findLongestNode(0, parent, adj);
		/* �ҵ���ڵ� x ��Զ�Ľڵ� y */
		int y = findLongestNode(x, parent, adj);
		/* ����ڵ� x ���ڵ� y ��·�� */
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


//��������
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
310. ��С�߶���

����һ������ͼ�������κ���������ֻͨ��һ��·�����ӡ� ���仰˵��һ���κ�û�м򵥻�·����ͨͼ����һ������

����һ�ð��� n ���ڵ���������Ϊ 0 �� n - 1 ���������� n ��һ���� n - 1 ������ߵ� edges �б�ÿһ���߶���һ�Ա�ǩ�������� edges[i] = [ai, bi] ��ʾ���нڵ� ai �� bi ֮�����һ������ߡ�

��ѡ�������κ�һ���ڵ���Ϊ������ѡ��ڵ� x ��Ϊ���ڵ�ʱ���������ĸ߶�Ϊ h �������п��ܵ����У�������С�߶ȵ���������min(h)������Ϊ ��С�߶��� ��

�����ҵ����е� ��С�߶��� ���� ����˳�� �������ǵĸ��ڵ��ǩ�б�

���� �߶� ��ָ���ڵ��Ҷ�ӽڵ�֮�������·���ϱߵ�������
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