#include<vector>

using namespace std;


/*
1735. ���ɳ˻�����ķ�����
����һ����ά�������� queries ������ queries[i] = [ni, ki] ���� i ����ѯ queries[i] Ҫ���쳤��Ϊ ni ��ÿ��Ԫ�ض��������������飬����������Ԫ�صĳ˻�Ϊ ki �������ҳ��ж����ֿ��еķ��������ڴ𰸿��ܻ�ܴ󣬷�������Ҫ�� 109 + 7 ȡ�� ��

���㷵��һ���������� answer������ answer.length == queries.length ������ answer[i]�ǵ� i ����ѯ�Ľ����
*/
typedef long long LL;
const int N = 10050;
class Solution {
public:
	const int mod = 1e9 + 7;
	int f[N], g[N];
	int qmi(int a, int b)
	{
		int res = 1;
		while (b)
		{
			if (b & 1) res = (LL)res * a % mod;
			a = (LL)a * a % mod;
			b >>= 1;
		}
		return res;
	}

	int cal(int a, int b)
	{
		return (LL)f[a] * g[b] % mod * g[a - b] % mod;
	}

	vector<int> waysToFillArray(vector<vector<int>>& queries) {
		f[0] = g[0] = 1;
		for (int i = 1; i < N; i++)
		{
			f[i] = (LL)f[i - 1] * i % mod;
			g[i] = qmi(f[i], mod - 2);
		}

		vector<int> ans;
		for (auto& q : queries)
		{
			int n = q[0], m = q[1];
			int res = 1;
			for (int i = 2; i * i <= m; i++)
			{
				if (m % i == 0)
				{
					int s = 0;
					while (m % i == 0) s++, m /= i;
					res = (LL)res * cal(n + s - 1, n - 1) % mod;
				}
			}
			if (m > 1) res = (LL)res * cal(n, n - 1) % mod;
			ans.push_back(res);
		}
		return ans;
	}
};


