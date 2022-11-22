#include<vector>
#include <algorithm>

using namespace std;


/*
1489. 找到最小生成树里的关键边和伪关键边
给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。

请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。

请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。
*/
class Solution {
public:
	vector<int> p;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	int work1(int n, vector<vector<int>>& edges, int k) {
		//不用第k条边
		for (int i = 0; i < n; i++) p[i] = i;

		int res = 0, cnt = 0;
		for (auto& e : edges)
		{
			if (e[3] == k) continue;
			int a = e[1], b = e[2], w = e[0];
			if (find(a) != find(b)) {
				res += w;
				p[find(a)] = find(b);
				cnt--;
			}
		}
		if (cnt > 1) res = INT_MAX;
		return res;
	}


	int work2(int n, vector<vector<int>>& edges, int k) {
		//必须用第k条边
		for (int i = 0; i < n; i++) p[i] = i;

		int res = 0, cnt = 0;

		for (auto& e : edges)
		{
			if (e[3] == k) {
				int a = e[1], b = e[2], w = e[0];
				if (find(a) != find(b)) {
					res += w;
					p[find(a)] = find(b);
					cnt--;
				}
				break;
			}
		}

		for (auto& e : edges)
		{
			if (e[3] == k) continue;
			int a = e[1], b = e[2], w = e[0];
			if (find(a) != find(b)) {
				res += w;
				p[find(a)] = find(b);
				cnt--;
			}
		}
		if (cnt > 1) res = INT_MAX;
		return res;
	}

	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
		int m = edges.size();
		for (int i = 0; i < m; i++)
		{
			auto& e = edges[i];
			swap(e[0], e[2]);
			e.push_back(i);
		}
		p = vector<int>(n);

		sort(edges.begin(), edges.end());
		int cost = work1(n, edges, -1);
		vector<vector<int>> res(2);
		for (int k = 0; k < m; k++)
		{
			if (work1(n, edges, k) != cost) res[0].push_back(k);
			else if (work2(n, edges, k) == cost) res[1].push_back(k);
		}
		return res;
	}
};