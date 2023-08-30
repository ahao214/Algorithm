#include<vector>
#include<unordered_set>


using namespace std;


/*
1761. 一个图中连通三元组的最小度数

给你一个无向图，整数 n 表示图中节点的数目，edges 数组表示图中的边，其中 edges[i] = [ui, vi] ，表示 ui 和 vi 之间有一条无向边。

一个 连通三元组 指的是 三个 节点组成的集合且这三个点之间 两两 有边。

连通三元组的度数 是所有满足此条件的边的数目：一个顶点在这个三元组内，而另一个顶点不在这个三元组内。

请你返回所有连通三元组中度数的 最小值 ，如果图中没有连通三元组，那么返回 -1 。
*/
class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		unordered_set<int> hash;
		vector<int> d(n + 1);
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			if (a > b) swap(a, b);
			d[a]++, d[b]++;
			hash.insert(a * 1000 + b);
		}

		int res = INT_MAX;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (hash.count(i * 1000 + j))
					for (int k = j + 1; k <= n; k++)
						if (hash.count(i * 1000 + k) && hash.count(j * 1000 + k))
							res = min(res, d[i] + d[j] + d[k] - 6);
			}
		}

		if (res == INT_MAX)
			res = -1;
		return res;
	}
};



class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> g(n, vector<int>(n));
		vector<int> degree(n);

		for (auto&& edge : edges) {
			int x = edge[0] - 1, y = edge[1] - 1;
			g[x][y] = g[y][x] = 1;
			++degree[x];
			++degree[y];
		}

		int ans = INT_MAX;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (g[i][j] == 1) {
					for (int k = j + 1; k < n; ++k) {
						if (g[i][k] == 1 && g[j][k] == 1) {
							ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
						}
					}
				}
			}
		}

		return ans == INT_MAX ? -1 : ans;
	}
};



class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		// 原图
		vector<unordered_set<int>> g(n);
		// 定向后的图
		vector<vector<int>> h(n);
		vector<int> degree(n);

		for (auto&& edge : edges) {
			int x = edge[0] - 1, y = edge[1] - 1;
			g[x].insert(y);
			g[y].insert(x);
			++degree[x];
			++degree[y];
		}
		for (auto&& edge : edges) {
			int x = edge[0] - 1, y = edge[1] - 1;
			if (degree[x] < degree[y] || (degree[x] == degree[y] && x < y)) {
				h[x].push_back(y);
			}
			else {
				h[y].push_back(x);
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i < n; ++i) {
			for (int j : h[i]) {
				for (int k : h[j]) {
					if (g[i].count(k)) {
						ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
					}
				}
			}
		}

		return ans == INT_MAX ? -1 : ans;
	}
};
