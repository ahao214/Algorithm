#include<vector>
#include <string>

using namespace std;




/*
2472. 不重叠回文子字符串的最大数目

给你一个字符串 s 和一个正整数 k 。

从字符串 s 中选出一组满足下述条件且 不重叠 的子字符串：

每个子字符串的长度 至少 为 k 。
每个子字符串是一个 回文串 。
返回最优方案中能选择的子字符串的 最大 数目。

子字符串 是字符串中一个连续的字符序列。
*/
class Solution {
public:
	int maxPalindromes(string s, int k) {
		int n = s.size();
		vector<vector<int>>isPalin(n, vector<int>(n));

		for (int i = 0; i < n; i++) {
			isPalin[i][i] = true;
		}
		for (int i = 0; i + 1 < n; i++) {
			isPalin[i][i + 1] = (s[i] == s[i + 1]);
		}

		for (int len = 3; len <= n; len++) {
			for (int i = 0; i + len - 1 < n; i++) {
				int j = i + len - 1;
				if (s[i] == s[j])
					isPalin[i][j] = isPalin[i + 1][j - 1];
			}
		}

		vector<int>dp(n);
		for (int i = k - 1; i < n; i++) {
			dp[i] = (i == 0 ? 0 : dp[i - 1]);
			for (int j = 0; j <= i - k + 1; j++) {
				if (isPalin[j][i])
					dp[i] = max(dp[i], (j == 0 ? 0 : dp[j - 1]) + 1);
			}
		}
		return dp[n - 1];
	}
};
