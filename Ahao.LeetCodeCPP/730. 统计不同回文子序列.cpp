using namespace std;

#include<vector>
#include<string>



//动态规划(使用三维数组)
class Solution {
public:
	const int MOD = 1e9 + 7;

	int countPalindromicSubsequences(string& s) {
		int n = s.size();
		vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
		for (int i = 0; i < n; i++) {
			dp[s[i] - 'a'][i][i] = 1;
		}

		for (int len = 2; len <= n; len++) {
			for (int i = 0, j = len - 1; j < n; i++, j++) {
				for (char c = 'a', k = 0; c <= 'd'; c++, k++) {
					if (s[i] == c && s[j] == c) {
						dp[k][i][j] = (2LL + dp[0][i + 1][j - 1] + dp[1][i + 1][j - 1] + dp[2][i + 1][j - 1] + dp[3][i + 1][j - 1]) % MOD;
					}
					else if (s[i] == c) {
						dp[k][i][j] = dp[k][i][j - 1];
					}
					else if (s[j] == c) {
						dp[k][i][j] = dp[k][i + 1][j];
					}
					else {
						dp[k][i][j] = dp[k][i + 1][j - 1];
					}
				}
			}
		}

		int res = 0;
		for (int i = 0; i < 4; i++) {
			res = (res + dp[i][0][n - 1]) % MOD;
		}
		return res;
	}
};



//动态规划(用二维数组)
class Solution {
public:
	const int MOD = 1e9 + 7;

	int countPalindromicSubsequences(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		vector<vector<int>> next(n, vector<int>(4));
		vector<vector<int>> pre(n, vector<int>(4));

		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
		}

		vector<int> pos(4, -1);

		for (int i = 0; i < n; i++) {
			for (int c = 0; c < 4; c++) {
				pre[i][c] = pos[c];
			}
			pos[s[i] - 'a'] = i;
		}

		pos[0] = pos[1] = pos[2] = pos[3] = n;

		for (int i = n - 1; i >= 0; i--) {
			for (int c = 0; c < 4; c++) {
				next[i][c] = pos[c];
			}
			pos[s[i] - 'a'] = i;
		}

		for (int len = 2; len <= n; len++) {
			for (int i = 0; i + len <= n; i++) {
				int j = i + len - 1;
				if (s[i] == s[j]) {
					int low = next[i][s[i] - 'a'];
					int high = pre[j][s[i] - 'a'];
					if (low > high) {
						dp[i][j] = (2 + dp[i + 1][j - 1] * 2) % MOD;
					}
					else if (low == high) {
						dp[i][j] = (1 + dp[i + 1][j - 1] * 2) % MOD;
					}
					else {
						dp[i][j] = (0LL + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD;
					}
				}
				else {
					dp[i][j] = (0LL + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
				}
			}
		}

		return dp[0][n - 1];
	}
};
