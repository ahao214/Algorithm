#include<vector>
#include<string>


using namespace std;



/*
2478. 完美分割的方案数
给你一个字符串 s ，每个字符是数字 '1' 到 '9' ，再给你两个整数 k 和 minLength 。

如果对 s 的分割满足以下条件，那么我们认为它是一个 完美 分割：

s 被分成 k 段互不相交的子字符串。
每个子字符串长度都 至少 为 minLength 。
每个子字符串的第一个字符都是一个 质数 数字，最后一个字符都是一个 非质数 数字。质数数字为 '2' ，'3' ，'5' 和 '7' ，剩下的都是非质数数字。
请你返回 s 的 完美 分割数目。由于答案可能很大，请返回答案对 109 + 7 取余 后的结果。

一个 子字符串 是字符串中一段连续字符串序列。
*/
using LL = long long;
class Solution {
	LL dp[1005][1005];
	LL M = 1e9 + 7;
public:
	int beautifulPartitions(string s, int k, int minLength) {
		int n = s.size();
		s = "#" + s;

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (isprime(s[i])) {
					dp[i][j] = 0;
					continue;
				}
				for (int k = j; k + minLength - 1 <= i; k++) {
					if (isprime(s[k]))
					{
						dp[i][j] += dp[k - 1][j - 1];
						dp[i][j] %= M;
					}
				}
			}
		}
		return dp[n][k];
	}

	bool isprime(char ch) {
		return ch == '2' || ch == '3' || ch == '5' || ch == '7';
	}
};


using LL = long long;
class Solution {
	LL dp[1005][1005];
	LL M = 1e9 + 7;
public:
	int beautifulPartitions(string s, int k, int minLength) {
		int n = s.size();
		s = "#" + s;

		dp[0][0] = 1;
		for (int j = 1; j <= k; j++) {
			LL presum = 0;
			for (int i = 1; i <= n; i++) {
				if (i - minLength + 1 >= 1 && isprime(s[i - minLength + 1]) && !isprime(s[i - minLength])) {
					presum += dp[i - minLength][j - 1];
					presum %= M;
				}
				if (!isprime(s[i]))
				{
					dp[i][j] = presum % M;
				}
			}
		}
		return dp[n][k];
	}

	bool isprime(char ch) {
		return ch == '2' || ch == '3' || ch == '5' || ch == '7';
	}
};
