#include<vector>
#include <queue>

using namespace std;


/*
1483. 树节点的第 K 个祖先
给你一棵树，树上有 n 个节点，按从 0 到 n-1 编号。树以父节点数组的形式给出，其中 parent[i] 是节点 i 的父节点。树的根节点是编号为 0 的节点。

请你设计并实现 getKthAncestor(int node, int k) 函数，函数返回节点 node 的第 k 个祖先节点。如果不存在这样的祖先节点，返回 -1 。

树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。
*/
class Solution {
public:

	vector<vector<int>> f;
	vector<vector<int>> g;
	void TreeAncestor(int n, vector<int>& parent) {
		f = vector<vector<int>>(n, vector<int>(16, -1));
		g = vector<vector<int>>(n);
		int root = 0;
		for (int i = 0; i < n; i++)
		{
			if (parent[i] == -1) root = i;
			else
				g[parent[i]].push_back(i);
		}
		queue<int> q;
		q.push(root);
		while (q.size())
		{
			int x = q.front();
			q.pop();
			for (auto y : g[x])
			{
				f[y][0] = x;
				for (int k = 1; k < 16; k++)
				{
					if (f[y][k - 1] != -1)
						f[y][k] = f[f[y][k - 1]][k - 1];
				}
				q.push(y);
			}
		}
	}

	int getKthAncestor(int node, int k) {
		for (int i = 0; i < 16; i++)
		{
			if (k >> i & 1)
			{
				node = f[node][i];
				if (node == -1)
					return node;
			}
		}
		return node;
	}
};




/*
1483. 树节点的第 K 个祖先

给你一棵树，树上有 n 个节点，按从 0 到 n-1 编号。树以父节点数组的形式给出，其中 parent[i] 是节点 i 的父节点。树的根节点是编号为 0 的节点。

树节点的第 k 个祖先节点是从该节点到根节点路径上的第 k 个节点。

实现 TreeAncestor 类：

TreeAncestor（int n， int[] parent） 对树和父数组中的节点数初始化对象。
getKthAncestor(int node, int k) 返回节点 node 的第 k 个祖先节点。如果不存在这样的祖先节点，返回 -1 。
*/
class TreeAncestor {
	vector<vector<int>>p;
public:
	TreeAncestor(int n, vector<int>& parent)
	{
		vector<vector<int>>p(n, vector<int>(20, -1));  // p[i][j] means the 2^j-th ancestor for node i
		for (int i = 0; i < n; i++)
			p[i][0] = parent[i];

		for (int j = 1; j < 20; j++)
			for (int i = 0; i < n; i++)
			{
				if (p[i][j - 1] != -1)
					p[i][j] = p[p[i][j - 1]][j - 1];
			}
		this->p = p;
	}

	int getKthAncestor(int node, int k)
	{
		for (int i = 0; i < 20; i++)
		{
			if ((k >> i) & 1)
			{
				node = p[node][i];
				if (node == -1) break;
			}
		}
		return node;
	}
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
