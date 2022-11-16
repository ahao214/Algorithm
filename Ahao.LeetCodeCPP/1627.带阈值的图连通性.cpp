#include<vector>

using namespace std;


/*
1627. 带阈值的图连通性
有 n 座城市，编号从 1 到 n 。编号为 x 和 y 的两座城市直接连通的前提是： x 和 y 的公因数中，至少有一个 严格大于 某个阈值 threshold 。更正式地说，如果存在整数 z ，且满足以下所有条件，则编号 x 和 y 的城市之间有一条道路：

x % z == 0
y % z == 0
z > threshold
给你两个整数 n 和 threshold ，以及一个待查询数组，请你判断每个查询 queries[i] = [ai, bi] 指向的城市 ai 和 bi 是否连通（即，它们之间是否存在一条路径）。

返回数组 answer ，其中answer.length == queries.length 。如果第 i 个查询中指向的城市 ai 和 bi 连通，则 answer[i] 为 true ；如果不连通，则 answer[i] 为 false 。
*/
class Solution {
	vector<int> Father;
	int FindFather(int x)
	{
		if (Father[x] != x)
			Father[x] = FindFather(Father[x]);
		return Father[x];
	}

	void Union(int x, int y)
	{
		x = Father[x];
		y = Father[y];
		if (x < y) Father[y] = x;
		else Father[x] = y;
	}
public:
	vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
		Father.resize(n + 1);
		for (int i = 1; i <= n; i++)
			Father[i] = i;
		for (int k = threshold + 1; k <= n; k++)
		{
			for (int x = 2 * k; x <= n; x += k)
			{
				if (FindFather(x) != FindFather(k))
					Union(x, k);
			}
		}
		vector<bool> res;
		for (auto query : queries)
			res.push_back(FindFather(query[0]) == FindFather(query[1]));
		return res;
	}
};




class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
		p.resize(n + 1);
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int d = threshold + 1; d <= n; d++)
			for (int i = d * 2; i <= n; i += d)
				p[find(d)] = p[find(i)];

		vector<bool> res;
		for (auto& q : queries)
			res.push_back(find(q[0]) == find(q[1]));

		return res;
	}
};