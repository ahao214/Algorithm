#include<vector>

using namespace std;


/*
1735. 生成乘积数组的方案数
给你一个二维整数数组 queries ，其中 queries[i] = [ni, ki] 。第 i 个查询 queries[i] 要求构造长度为 ni 、每个元素都是正整数的数组，且满足所有元素的乘积为 ki ，请你找出有多少种可行的方案。由于答案可能会很大，方案数需要对 109 + 7 取余 。

请你返回一个整数数组 answer，满足 answer.length == queries.length ，其中 answer[i]是第 i 个查询的结果。
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


