#include<vector>
#include<queue>

using namespace std;


/*
1786. �ӵ�һ���ڵ���������һ���ڵ������·����
����һ����Ȩ������ͨͼ������һ�������� n ����ʾͼ���� n ���ڵ㣬������ 1 �� n ���ڵ��ţ������һ������ edges ������ÿ�� edges[i] = [ui, vi, weighti] ��ʾ����һ��λ�ڽڵ� ui �� vi ֮��ıߣ������ߵ�Ȩ��Ϊ weighti ��

�ӽڵ� start �������ڵ� end ��·����һ������ [z0, z1, z2, ..., zk] �Ľڵ����У����� z0 = start ��zk = end �������з��� 0 <= i <= k-1 �Ľڵ� zi �� zi+1 ֮�����һ���ߡ�

·���ľ��붨��Ϊ����·�������бߵ�Ȩ���ܺ͡��� distanceToLastNode(x) ��ʾ�ڵ� n �� x ֮��·������̾��롣����·�� Ϊ���� distanceToLastNode(zi) > distanceToLastNode(zi+1) ��һ��·�������� 0 <= i <= k-1 ��

���شӽڵ� 1 �������ڵ� n �� ����·���� ���������ֿ��ܴܺ��뷵�ض� 109 + 7 ȡ�� �Ľ����
*/
using PII = pair<int, int>;
#define x first
#define y second
class Solution {
public:
	const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
	vector<vector<PII>> g;
	vector<int> dist, f;
	vector<bool> st;

	int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		g.resize(n + 1), dist.resize(n + 1, INF), f.resize(n + 1), st.resize(n + 1);
		for (auto& e : edges)
		{
			int a = e[0], b = e[1], c = e[2];
			g[a].push_back({ b,c });
			g[b].push_back({ a,c });
		}

		queue<int> q;
		q.push(n);
		dist[n] = 0;
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			st[t] = false;

			for (auto& p : g[t])
			{
				int j = p.x, w = p.y;
				if (dist[j] > dist[t] + w)
				{
					dist[j] = dist[t] + w;
					if (!st[j])
					{
						q.push(j);
						st[j] = true;
					}
				}
			}
		}
		vector<PII> vs;
		for (int i = 1; i <= n; i++)
			vs.push_back({ dist[i],i });
		sort(vs.begin(), vs.end());
		f[n] = 1;
		for (auto& v : vs)
		{
			int d = v.x, u = v.y;
			for (auto& p : g[u])
			{
				int j = p.x;
				if (d > dist[j])
					f[u] = (f[u] + f[j]) % MOD;
			}
		}
		return f[1];
	}
};

