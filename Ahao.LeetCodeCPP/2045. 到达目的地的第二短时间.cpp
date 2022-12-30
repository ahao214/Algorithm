#include<vector>
#include <queue>

using namespace std;


/*
2045. 到达目的地的第二短时间
城市用一个 双向连通 图表示，图中有 n 个节点，从 1 到 n 编号（包含 1 和 n）。图中的边用一个二维整数数组 edges 表示，其中每个 edges[i] = [ui, vi] 表示一条节点 ui 和节点 vi 之间的双向连通边。每组节点对由 最多一条 边连通，顶点不存在连接到自身的边。穿过任意一条边的时间是 time 分钟。

每个节点都有一个交通信号灯，每 change 分钟改变一次，从绿色变成红色，再由红色变成绿色，循环往复。所有信号灯都 同时 改变。你可以在 任何时候 进入某个节点，但是 只能 在节点 信号灯是绿色时 才能离开。如果信号灯是  绿色 ，你 不能 在节点等待，必须离开。

第二小的值 是 严格大于 最小值的所有值中最小的值。

例如，[2, 3, 4] 中第二小的值是 3 ，而 [2, 2, 4] 中第二小的值是 4 。
给你 n、edges、time 和 change ，返回从节点 1 到节点 n 需要的 第二短时间 。
*/
class Solution {
public:
	struct Point {
		//kind:0 是最短路 1是次短路
		int dis, v, kind;
		bool operator< (const Point& p) const {
			return dis > p.dis;
		}
	};

	int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		vector<vector<int>> g(n);
		for (auto& e : edges) {
			//[1,n] -> [0,n-1]
			g[e[0] - 1].push_back(e[1] - 1);
			g[e[1] - 1].push_back(e[0] - 1);
		}
		priority_queue<Point> heap;
		vector<vector<int>> dis(n, vector<int>(2, 1e8)), vis(n, vector<int>(2));
		dis[0][0] = 0;
		heap.push({ 0,0,0 });
		while (!heap.empty()) {
			auto cur = heap.top().v, kind = heap.top().kind;
			heap.pop();
			if (vis[cur][kind]) continue;
			vis[cur][kind] = 1;
			//红绿灯
			int d = dis[cur][kind] + time;
			if ((dis[cur][kind] / change) % 2) {
				d += change - dis[cur][kind] % change;
			}
			for (auto v : g[cur]) {
				if (d < dis[v][0]) {
					dis[v][1] = dis[v][0];
					heap.push({ dis[v][1],v,1 });
					dis[v][0] = d;
					heap.push({ dis[v][0],v,0 });
				}
				else if (d > dis[v][0] && d < dis[v][1]) {
					dis[v][1] = d;
					heap.push({ dis[v][1],v,1 });
				}
			}
		}
		return dis[n - 1][1];
	}
};