#include<vector>

using namespace std;



/*
1916. ͳ��Ϊ��Ⱥ��������Ĳ�ͬ˳��
����һֻ���ϣ�����Ϊ��Ⱥ���� n ���Ŵ� 0 �� n-1 ���·��䡣����һ�� �±�� 0 ��ʼ �ҳ���Ϊ n ���������� prevRoom ��Ϊ�����ƻ������У�prevRoom[i] ��ʾ�ڹ������� i ֮ǰ��������ȹ������� prevRoom[i] ������������������� ֱ�� ���������� 0 �Ѿ�������ɣ����� prevRoom[0] = -1 �������ƻ��л���һ��Ӳ��Ҫ����������з���Ĺ���֮�󣬴ӷ��� 0 ���Է��ʵ�ÿ�����䡣

��һ��ֻ�ܹ��� һ�� ���䡣������� �Ѿ������õ� ����֮�����ɴ��У�ֻҪ��Щ������ ������ ��������� prevRoom[i] �Ѿ�������ɣ���ô��Ϳ��Թ������� i��

�����㹹�����з���� ��ͬ˳�����Ŀ �����ڴ𰸿��ܴܺ��뷵�ض� 109 + 7 ȡ�� �Ľ����
*/
typedef long long LL;
const int N = 100010, MOD = 1e9 + 7;
int f[N], g[N];
int s[N], sz[N];
int h[N], e[N], ne[N], idx;

class Solution {
public:
	void add(int a, int b)
	{
		e[idx] = b, ne[idx] = h[a], h[a] = idx++;
	}

	int dfs(int u)
	{
		sz[u] = 0;
		for (int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			dfs(j);
			sz[u] += sz[j];
		}
		s[u] = f[sz[u]];
		for (int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			s[u] = (LL)s[u] * g[sz[j]] % MOD * s[j] % MOD;
		}
		sz[u]++;
		return s[u];
	}

	int qmi(int a, int k)
	{
		int res = 1;
		while (k)
		{
			if (k & 1) res = (LL)res * a % MOD;
			a = (LL)a * a % MOD;
			k >>= 1;
		}
		return res;
	}

	int waysToBuildRooms(vector<int>& prevRoom) {
		int n = prevRoom.size();
		memset(h, -1, sizeof h);
		idx = 0;

		f[0] = g[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			f[i] = (LL)f[i - 1] * i % MOD;
			g[i] = qmi(f[i], MOD - 2) % MOD;
		}

		for (int i = 1; i < n; i++)
			add(prevRoom[i], i);
		return dfs(0);
	}
};


