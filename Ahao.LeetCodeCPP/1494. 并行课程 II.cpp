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

