#include<vector>

using namespace std;



/*
1916. 统计为蚁群构筑房间的不同顺序
你是一只蚂蚁，负责为蚁群构筑 n 间编号从 0 到 n-1 的新房间。给你一个 下标从 0 开始 且长度为 n 的整数数组 prevRoom 作为扩建计划。其中，prevRoom[i] 表示在构筑房间 i 之前，你必须先构筑房间 prevRoom[i] ，并且这两个房间必须 直接 相连。房间 0 已经构筑完成，所以 prevRoom[0] = -1 。扩建计划中还有一条硬性要求，在完成所有房间的构筑之后，从房间 0 可以访问到每个房间。

你一次只能构筑 一个 房间。你可以在 已经构筑好的 房间之间自由穿行，只要这些房间是 相连的 。如果房间 prevRoom[i] 已经构筑完成，那么你就可以构筑房间 i。

返回你构筑所有房间的 不同顺序的数目 。由于答案可能很大，请返回对 109 + 7 取余 的结果。
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


