#include<vector>
#include<string>

using namespace std;


/*
1639. 通过给定词典构造目标字符串的方案数
*/
class Solution {
	long dp[1005][1005];
	long DOM = 1e9 + 7;
	long count[1005][1005];
public:
	int numWays(vector<string>& words, string target) {
		int n = target.size();
		int m = words[0].size();

		for (auto word : words)
		{
			for (int i = 0; i < m; i++)
				count[i + 1][word[i] - 'a'] += 1;
		}

		target = "#" + target;
		for (int k = 0; k <= m; k++)
			dp[0][k] = 1;


		for (int i = 1; i <= n; i++)
			for (int k = 1; k <= m; k++)
			{
				dp[i][k] = dp[i][k - 1];
				if (count[k][target[i] - 'a'] > 0)
					dp[i][k] += dp[i - 1][k - 1] * count[k][target[i] - 'a'] % DOM;
				dp[i][k] %= DOM;
			}
		return dp[n][m];
	}
};

