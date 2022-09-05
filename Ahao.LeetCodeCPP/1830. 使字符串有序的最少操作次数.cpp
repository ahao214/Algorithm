#include<vector>
#include<string>

using namespace std;


/*
1830. 使字符串有序的最少操作次数
给你一个字符串 s （下标从 0 开始）。你需要对 s 执行以下操作直到它变为一个有序字符串：

找到 最大下标 i ，使得 1 <= i < s.length 且 s[i] < s[i - 1] 。
找到 最大下标 j ，使得 i <= j < s.length 且对于所有在闭区间 [i, j] 之间的 k 都有 s[k] < s[i - 1] 。
交换下标为 i - 1​​​​ 和 j​​​​ 处的两个字符。
将下标 i 开始的字符串后缀反转。
请你返回将字符串变成有序的最少操作次数。由于答案可能会很大，请返回它对 109 + 7 取余 的结果。
*/
typedef long long LL;
const int MOD = 1e9 + 7;
const int N = 3010;

class Solution {
public:
	LL f[N], g[N];
	LL qmi(LL a, LL b)
	{
		LL res = 1;
		while (b)
		{
			if (b & 1) res = res * a % MOD;
			a = a * a % MOD;
			b >>= 1;
		}
		return res;
	}

	int get(int cnt[])
	{
		int sum = 0;
		for (int i = 0; i < 26; i++)
			sum += cnt[i];
		int res = f[sum];
		for (int i = 0; i < 26; i++)
			res = (LL)res * g[cnt[i]] % MOD;
		return res;
	}

	int makeStringSorted(string s) {
		f[0] = g[0] = 1;
		for (int i = 1; i <= s.size(); i++)
		{
			f[i] = f[i - 1] * i % MOD;
			g[i] = qmi(f[i], MOD - 2);
		}

		int res = 0;
		int cnt[26] = { 0 };
		for (auto c : s) cnt[c - 'a']++;
		for (auto c : s)
		{
			int x = c - 'a';
			for (int i = 0; i < x; i++)
			{
				if (!cnt[i]) continue;
				cnt[i]--;
				res = (res + get(cnt)) % MOD;
				cnt[i]++;
			}
			cnt[x]--;
		}
		return res;
	}
};