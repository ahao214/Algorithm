#include<vector>
#include<queue>

using namespace std;


/*
1928. �涨ʱ���ڵ����յ����С����
һ�������� n �����У����б��Ϊ 0 �� n - 1 ����Ŀ��֤ ���г��� ����˫���· ������һ�� ����·�ɶ�ά�������� edges ��ʾ������ edges[i] = [xi, yi, timei] ��ʾ���� xi �� yi ֮����һ��˫���·���ķ�ʱ��Ϊ timei ���ӡ���������֮����ܻ��ж����ķ�ʱ�䲻ͬ�ĵ�·�����ǲ����е�·��ͷ������ͬһ�����С�

ÿ�ξ���һ������ʱ������Ҫ��ͨ�зѡ�ͨ�з���һ������Ϊ n ���±�� 0 ��ʼ���������� passingFees ��ʾ������ passingFees[j] ���㾭������ j ��Ҫ֧���ķ��á�

һ��ʼ�����ڳ��� 0 ������Ҫ�� maxTime �������� ������ maxTime ���ӣ�������� n - 1 �����е� ���� Ϊ�㾭�������г��� ͨ�з�֮�� ������ �����յ���е�ͨ�зѣ���

���� maxTime��edges �� passingFees �����㷵��������е� ��С���� ������޷��� maxTime ��������������У����㷵�� -1 ��
*/

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1010, M = 2010, INF = 0x3f3f3f3f;

int h[N], e[M], w[M], ne[M], idx;
int dist[N][N];
bool st[N][N];

class Solution {
public:
	void add(int a, int b, int c)
	{
		e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
	}

	int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
		int n = passingFees.size();
		memset(h, -1, sizeof h), idx = 0;
		for (auto& e : edges)
		{
			int a = e[0], b = e[1], c = e[2];
			add(a, b, c), add(b, a, c);
		}
		memset(dist, 0x3f, sizeof dist);
		dist[0][0] = passingFees[0];
		queue<PII> q;
		q.push({ 0,0 });

		while (q.size())
		{
			auto t = q.front();
			q.pop();
			st[t.x][t.y] = false;

			for (int i = h[t.x]; ~i; i = ne[i])
			{
				int x = e[i], y = t.y + w[i];
				if (y > maxTime) continue;
				if (dist[x][y] > dist[t.x][t.y] + passingFees[x])
				{
					dist[x][y] = dist[t.x][t.y] + passingFees[x];
					if (!st[x][y])
					{
						st[x][y] = true;
						q.push({ x,y });
					}
				}
			}
		}

		int res = INF;
		for (int i = 0; i <= maxTime; i++)
			res = min(res, dist[n - 1][i]);
		if (res == INF) return -1;
		return res;
	}
};
