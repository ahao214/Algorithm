#include<vector>
#include <string>

using namespace std;


/*
1519. 子树中标签相同的节点数
给你一棵树（即，一个连通的无环无向图），这棵树由编号从 0  到 n - 1 的 n 个节点组成，且恰好有 n - 1 条 edges 。树的根节点为节点 0 ，树上的每一个节点都有一个标签，也就是字符串 labels 中的一个小写字符（编号为 i 的 节点的标签就是 labels[i] ）

边数组 edges 以 edges[i] = [ai, bi] 的形式给出，该格式表示节点 ai 和 bi 之间存在一条边。

返回一个大小为 n 的数组，其中 ans[i] 表示第 i 个节点的子树中与节点 i 标签相同的节点数。

树 T 中的子树是由 T 中的某个节点及其所有后代节点组成的树。
*/
class Solution {
public:
	vector<vector<int>> f;
	vector<vector<int>> g;
	string w;

	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		g.resize(n);
		f = vector<vector<int>>(n, vector<int>(26));
		w = labels;

		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			g[a].push_back(b), g[b].push_back(a);
		}

		dfs(0, -1);
		vector<int> res(n);
		for (int i = 0; i < n; i++) res[i] = f[i][w[i] - 'a'];
		return res;
	}

	void dfs(int u, int father)
	{
		f[u][w[u] - 'a'] = 1;
		for (auto son : g[u])
		{
			if (son == father) continue;
			dfs(son, u);
			for (int j = 0; j < 26; j++)
			{
				f[u][j] += f[son][j];
			}
		}
	}
};