#include<vector>
#include <algorithm>

using namespace std;



/*
1697. 检查边长度限制的路径是否存在
给你一个 n 个点组成的无向图边集 edgeList ，其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi 的边。请注意，两个点之间可能有 超过一条边 。

给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj] ，你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径，且这条路径上的每一条边都 严格小于 limitj 。

请你返回一个 布尔数组 answer ，其中 answer.length == queries.length ，当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false 。
*/
const int N = 100010;
struct Node {
	int a, b, c, d;
	bool operator< (const Node& t) const {
		return c < t.c;
	}
}e[N], q[N];

class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x)
			p[x] = find(p[x]);
		return p[x];
	}

	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		int m = edgeList.size(), k = queries.size();

		for (int i = 0; i < m; i++)
			e[i] = { edgeList[i][0],edgeList[i][1],edgeList[i][2] };
		for (int i = 0; i < k; i++)
			q[i] = { queries[i][0],queries[i][1],queries[i][2],i };

		sort(e, e + m), sort(q, q + k);

		p.resize(n);
		for (int i = 0; i < n; i++) p[i] = i;
		vector<bool> res(k);

		for (int i = 0, j = 0; i < k; i++)
		{
			while (j < m && e[j].c < q[i].c)
			{
				int a = e[j].a, b = e[j].b;
				p[find(a)] = find(b);
				j++;
			}
			res[q[i].d] = find(q[i].a) == find(q[i].b);
		}
		return res;
	}
};


class Solution {
public:
	int find(vector<int>& uf, int x) {
		if (uf[x] == x) {
			return x;
		}
		return uf[x] = find(uf, uf[x]);
	}

	void merge(vector<int>& uf, int x, int y) {
		x = find(uf, x);
		y = find(uf, y);
		uf[y] = x;
	}

	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		sort(edgeList.begin(), edgeList.end(), [](vector<int>& e1, vector<int>& e2) {
			return e1[2] < e2[2];
			});

		vector<int> index(queries.size());
		iota(index.begin(), index.end(), 0);
		sort(index.begin(), index.end(), [&](int i1, int i2) {
			return queries[i1][2] < queries[i2][2];
			});

		vector<int> uf(n);
		iota(uf.begin(), uf.end(), 0);
		vector<bool> res(queries.size());
		int k = 0;
		for (auto i : index) {
			while (k < edgeList.size() && edgeList[k][2] < queries[i][2]) {
				merge(uf, edgeList[k][0], edgeList[k][1]);
				k++;
			}
			res[i] = find(uf, queries[i][0]) == find(uf, queries[i][1]);
		}
		return res;
	}
};
