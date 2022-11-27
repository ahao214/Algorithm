#include<vector>

using namespace std;


/*
2400. 恰好移动 k 步到达某一位置的方法数目

给你两个 正 整数 startPos 和 endPos 。最初，你站在 无限 数轴上位置 startPos 处。在一步移动中，你可以向左或者向右移动一个位置。

给你一个正整数 k ，返回从 startPos 出发、恰好 移动 k 步并到达 endPos 的 不同 方法数目。由于答案可能会很大，返回对 109 + 7 取余 的结果。

如果所执行移动的顺序不完全相同，则认为两种方法不同。

注意：数轴包含负整数。
*/
using LL = long long;
LL M = 1e9 + 7;
class Solution {
public:
	int numberOfWays(int startPos, int endPos, int k) {
		LL offset = k;
		LL d = abs(endPos - startPos);
		if (d > k)
			return 0;

		vector<vector<LL>>dp(k + 1, vector<LL>(2 * k + 5, 0));
		dp[0][0 + offset] = 1;

		for (int t = 1; t <= k; t++) {
			for (int p = -k; p <= +k; p++) {
				if (p - 1 >= -k) {
					dp[t][p + offset] = (dp[t][p + offset] + dp[t - 1][p - 1 + offset]) % M;
				}
				if (p + 1 <= k) {
					dp[t][p + offset] = (dp[t][p + offset] + dp[t - 1][p + 1 + offset]) % M;
				}
			}
		}
		return dp[k][d + offset];
	}
};