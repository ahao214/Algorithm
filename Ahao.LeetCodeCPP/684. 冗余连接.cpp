#include<vector>

using namespace std;


/*
684. 冗余连接
树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		for (int i = 0; i <= n; i++)
		{
			p.push_back(i);
		}
		for (auto e : edges)
		{
			int a = e[0], b = e[1];
			if (find(a) == find(b)) return { a,b };
			p[find(a)] = find(b);
		}
		return { -1,-1 };
	}
};