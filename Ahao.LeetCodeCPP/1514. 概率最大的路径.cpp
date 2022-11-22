#include<vector>
#include<queue>

using namespace std;


/*
1514. ��������·��
����һ���� n ���ڵ㣨�±�� 0 ��ʼ����ɵ������Ȩͼ����ͼ��һ�������ߵ��б���ɣ����� edges[i] = [a, b] ��ʾ���ӽڵ� a �� b ��һ������ߣ��Ҹñ߱����ɹ��ĸ���Ϊ succProb[i] ��

ָ�������ڵ�ֱ���Ϊ��� start ���յ� end �������ҳ�����㵽�յ�ɹ���������·������������ɹ����ʡ�

��������ڴ� start �� end ��·������ ���� 0 ��ֻҪ�����׼�𰸵������� 1e-5 ���ͻᱻ������ȷ�𰸡�
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