#include<vector>
#include<string>

using namespace std;


/*
1857. 有向图中最大颜色值
给你一个 有向图 ，它含有 n 个节点和 m 条边。节点编号从 0 到 n - 1 。

给你一个字符串 colors ，其中 colors[i] 是小写英文字母，表示图中第 i 个节点的 颜色 （下标从 0 开始）。同时给你一个二维数组 edges ，其中 edges[j] = [aj, bj] 表示从节点 aj 到节点 bj 有一条 有向边 。

图中一条有效 路径 是一个点序列 x1 -> x2 -> x3 -> ... -> xk ，对于所有 1 <= i < k ，从 xi 到 xi+1 在图中有一条有向边。路径的 颜色值 是路径中 出现次数最多 颜色的节点数目。

请你返回给定图中有效路径里面的 最大颜色值 。如果图中含有环，请返回 -1 。
*/
class Solution {
public:
	int largestPathValue(string colors, vector<vector<int>>& edges) {
		int n = colors.size();
		vector<vector<int>>g(n), f(n, vector<int>(26));
		vector<int> d(n), p;
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			g[a].push_back(b);
			d[b]++;
		}
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			if (!d[i])
				q.push(i);
		}

		while (q.size())
		{
			auto t = q.front();
			q.pop();
			p.push_back(t);

			for (int j : g[t])
				if (!--d[j])
					q.push(j);
		}

		if (p.size() < n) return -1;
		int res = 0;
		for (int i : p)
		{
			int c = colors[i] - 'a';
			f[i][c] = max(f[i][c], 1);
			for (int j = 0; j < 26; j++)
			{
				for (int k : g[i])
				{
					int t = 0;
					if (colors[k] - 'a' == j) t = 1;
					f[k][j] = max(f[k][j], f[i][j] + t);
				}
				res = max(res, f[i][j]);
			}
		}
		return res;
	}
};