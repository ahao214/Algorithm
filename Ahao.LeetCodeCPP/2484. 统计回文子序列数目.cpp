#include<vector>
#include <string>

using namespace std;




/*
2484. 统计回文子序列数目
给你数字字符串 s ，请你返回 s 中长度为 5 的 回文子序列 数目。由于答案可能很大，请你将答案对 109 + 7 取余 后返回。

提示：

如果一个字符串从前往后和从后往前读相同，那么它是 回文字符串 。
子序列是一个字符串中删除若干个字符后，不改变字符顺序，剩余字符构成的字符串。
*/

using LL = long long;
LL MOD = 1e9 + 7;
class Solution {
	LL dp1[10005][10][10];
	LL count1[10005][10];

	LL dp2[10005][10][10];
	LL count2[10005][10];
public:
	int countPalindromes(string s) {
		int n = s.size();
		s = "#" + s;

		for (int j = 0; j <= 9; j++) {
			LL sum = 0;
			for (int i = 1; i <= n; i++) {
				sum += (s[i] == '0' + j);
				count1[i][j] = sum;
			}
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					dp1[i][j][k] = dp1[i - 1][j][k];
					if (s[i] == '0' + k) {
						dp1[i][j][k] = (dp1[i][j][k] + count1[i - 1][j]) % MOD;
					}
				}
			}
		}


		for (int j = 0; j <= 9; j++) {
			LL sum = 0;
			for (int i = n; i >= 1; i--) {
				sum += (s[i] == '0' + j);
				count2[i][j] = sum;
			}
		}

		for (int i = n - 1; i >= 1; i--) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					dp2[i][j][k] = dp2[i + 1][j][k];
					if (s[i] == '0' + k) {
						dp2[i][j][k] = (dp2[i][j][k] + count2[i + 1][j]) % MOD;
					}
				}
			}
		}

		LL res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					res += dp1[i - 1][j][k] * dp2[i + 1][j][k] % MOD;
					res %= MOD;
				}
			}
		}
		return res;
	}
};