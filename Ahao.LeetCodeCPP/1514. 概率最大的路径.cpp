#include<vector>
#include<queue>

using namespace std;


/*
1514. 概率最大的路径
给你一个由 n 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 edges[i] = [a, b] 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 succProb[i] 。

指定两个节点分别作为起点 start 和终点 end ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。

如果不存在从 start 到 end 的路径，请 返回 0 。只要答案与标准答案的误差不超过 1e-5 ，就会被视作正确答案。
*/
class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		typedef pair<int, double> PID;
		vector<vector<PID>> g(n);
		for (int i = 0; i < edges.size(); i++)
		{
			int a = edges[i][0], b = edges[i][1];
			double c = succProb[i];
			g[a].push_back({ b,c });
			g[b].push_back({ a,c });
		}

		queue<int> q;
		q.push(start);
		vector<double> dist(n, 0);
		dist[start] = 1;
		vector<bool> st(n);

		while (q.size())
		{
			auto t = q.front();
			q.pop();
			st[t] = false;

			for (auto e : g[t])
			{
				int ver = e.first;
				double w = e.second;
				if (dist[ver] < dist[t] * w)
				{
					dist[ver] = dist[t] * w;
					if (!st[ver])
					{
						q.push(ver);
						st[ver] = false;
					}
				}
			}
		}
		return dist[end];
	}
};