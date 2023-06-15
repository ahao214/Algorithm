#include<vector>


using namespace std;



/*
1494. ���пγ� II

����һ������ n ��ʾĳ����ѧ��γ̵���Ŀ�����Ϊ 1 �� n ������ dependencies �У� dependencies[i] = [xi, yi]  ��ʾһ�����޿εĹ�ϵ��Ҳ���ǿγ� xi �����ڿγ� yi ֮ǰ�ϡ�ͬʱ�㻹��һ������ k ��

��һ��ѧ���У��� ��� ����ͬʱ�� k �ſΣ�ǰ������Щ�ε����޿���֮ǰ��ѧ�����Ѿ��Ϲ��ˡ�

���㷵���������п�������Ҫ���ٸ�ѧ�ڡ���Ŀ��֤һ������һ���������пεķ�ʽ��
*/
class Solution {
public:
	const int INF = 1000;
	vector<int> f;
	int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
		f = vector<int>(1 << n, INF);
		for (auto& e : relations) e[0]--, e[1]--;

		f[0] = 0;
		for (int i = 0; i < 1 << n; i++)
		{
			vector<bool> st(n);
			for (auto& e : relations)
			{
				int x = e[0], y = e[1];
				if (!(i >> x & 1))
					st[y] = true;
			}
			int state = 0;
			for (int j = 0; j < n; j++)
				if (!st[j] && !(i >> j & 1))
					state += 1 << j;
			dfs(n, k, i, state, 0, 0);
		}
		return f[(1 << n) - 1];
	}

	void dfs(int n, int k, int i, int state, int now, int start) {
		if (!k || !state) {
			f[i | now] = min(f[i | now], f[i] + 1);
			return;
		}

		for (int j = start; j < n; j++)
		{
			if (state >> j & 1)
			{
				dfs(n, k - 1, i, state - (1 << j), now + (1 << j), j + 1);
			}
		}
	}
};



class Solution {
public:
	int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
		vector<int> dp(1 << n, INT_MAX);
		vector<int> need(1 << n, 0);
		for (auto& edge : relations) {
			need[(1 << (edge[1] - 1))] |= 1 << (edge[0] - 1);
		}
		dp[0] = 0;
		for (int i = 1; i < (1 << n); ++i) {
			need[i] = need[i & (i - 1)] | need[i & (-i)];
			if ((need[i] | i) != i) { // i ��������һ�ſγ̵�ǰ�ÿγ�û�����ѧϰ
				continue;
			}
			int valid = i ^ need[i]; // ��ǰѧ�ڿ��Խ���ѧϰ�Ŀγ̼���
			if (__builtin_popcount(valid) <= k) { // �������С�� k�������ȫ��ѧϰ������ö���Ӽ�
				dp[i] = min(dp[i], dp[i ^ valid] + 1);
			}
			else { // ����ö�ٵ�ǰѧ����Ҫ����ѧϰ�Ŀγ̼���
				for (int sub = valid; sub; sub = (sub - 1) & valid) {
					if (__builtin_popcount(sub) <= k) {
						dp[i] = min(dp[i], dp[i ^ sub] + 1);
					}
				}
			}
		}
		return dp[(1 << n) - 1];
	}
};

