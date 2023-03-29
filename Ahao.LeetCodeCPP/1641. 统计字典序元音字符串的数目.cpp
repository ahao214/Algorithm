#include<vector>
#include <numeric>

using namespace std;



/*
1641. 统计字典序元音字符串的数目

给你一个整数 n，请返回长度为 n 、仅由元音 (a, e, i, o, u) 组成且按 字典序排列 的字符串数量。

字符串 s 按 字典序排列 需要满足：对于所有有效的 i，s[i] 在字母表中的位置总是与 s[i+1] 相同或在 s[i+1] 之前。
*/
class Solution {
	int dp[51][5];
public:
	int countVowelStrings(int n) {
		for (int k = 0; k < 5; k++)
			dp[0][k] = 1;

		for (int i = 1; i < n; i++)
			for (int k = 0; k < 5; k++)
			{
				for (int j = 0; j <= k; j++)
					dp[i][k] += dp[i - 1][j];
			}
		int res = 0;
		for (int k = 0; k < 5; k++)
			res += dp[n - 1][k];
		return res;
	}
};


class Solution {
public:
	int countVowelStrings(int n) {
		return comb(n + 4, 4);
	}

	int comb(int n, int m)
	{
		long long cnt = 1;
		for (int i = 0; i < m; i++)
		{
			cnt *= n - i;
			cnt /= i + 1;
		}
		return cnt;
	}
};




//组合数字
class Solution {
public:
	int countVowelStrings(int n) {
		return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
	}
};


//动态规划
class Solution {
public:
	int countVowelStrings(int n) {
		vector<int> dp(5, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < 5; j++) {
				dp[j] += dp[j - 1];
			}
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};