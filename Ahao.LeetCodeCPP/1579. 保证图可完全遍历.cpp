#include<string>
#include<vector>


using namespace std;




/*
1579. 保证图可完全遍历
Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：

类型 1：只能由 Alice 遍历。
类型 2：只能由 Bob 遍历。
类型 3：Alice 和 Bob 都可以遍历。
给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。

返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1
*/
class Solution {
public:
	vector<int> pa, pb;

	int find(vector<int>& p, int x)
	{
		if (p[x] != x) p[x] = find(p, p[x]);
		return p[x];
	}

	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		pa.resize(n + 1), pb.resize(n + 1);
		for (int i = 1; i <= n; i++) pa[i] = pb[i] = i;

		int res = 0, ca = n, cb = n;
		for (auto& e : edges)
		{
			if (e[0] == 3)
			{
				int x = e[1], y = e[2];
				int pax = find(pa, x), pay = find(pa, y);
				int pbx = find(pb, x), pby = find(pb, y);
				if (pax != pay)
				{
					pa[pax] = pay, ca--;
					pb[pbx] = pby, cb--;
				}
				else res++;
			}
		}

		for (auto& e : edges)
		{
			int t = e[0], x = e[1], y = e[2];
			if (t == 3) continue;
			if (t == 1)
			{
				int pax = find(pa, x), pay = find(pa, y);
				if (pax != pay)
				{
					pa[pax] = pay, ca--;
				}
				else res++;
			}
			else {
				int pbx = find(pb, x), pby = find(pb, y);
				if (pbx != pby)
				{
					pb[pbx] = pby, cb--;
				}
				else res++;
			}
		}

		if (ca > 1 || cb > 1) return -1;
		return res;
	}
};