#include<vector>

using namespace std;



/*
1466. 重新规划路线
n 座城市，从 0 到 n-1 编号，其间共有 n-1 条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输部决定重新规划路线，以改变交通拥堵的状况。

路线用 connections 表示，其中 connections[i] = [a, b] 表示从城市 a 到 b 的一条有向路线。

今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。

请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。

题目数据 保证 每个城市在重新规划路线方向后都能到达城市 0 。
*/
class Solution {
public:
	vector<vector<pair<int, int>>> g;
	int minReorder(int n, vector<vector<int>>& connections) {
		g = vector<vector<pair<int, int>>>(n);
		for (auto e : connections)
		{
			int a = e[0], b = e[1];
			g[a].push_back({ b,1 });
			g[b].push_back({ a,0 });
		}
		return dfs(0, -1);
	}

	int dfs(int u, int father)
	{
		int res = 0;
		for (auto e : g[u])
		{
			int ver = e.first, dir = e.second;
			if (ver == father) continue;
			res += dfs(ver, u) + dir;
		}
		return res;
	}
};
