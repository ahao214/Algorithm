#include<vector>
#include <string>

using namespace std;



/*
2430. 对字母串可执行的最大删除数
给你一个仅由小写英文字母组成的字符串 s 。在一步操作中，你可以：

删除 整个字符串 s ，或者
对于满足 1 <= i <= s.length / 2 的任意 i ，如果 s 中的 前 i 个字母和接下来的 i 个字母 相等 ，删除 前 i 个字母。
例如，如果 s = "ababc" ，那么在一步操作中，你可以删除 s 的前两个字母得到 "abc" ，因为 s 的前两个字母和接下来的两个字母都等于 "ab" 。

返回删除 s 所需的最大操作数。
*/
class Solution {
	int lcs[4005][4005];
	int dp[4005];
public:
	int deleteString(string s) {
		int n = s.size();
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (s[i] == s[j]) {
					lcs[i][j] = lcs[i + 1][j + 1] + 1;
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = 1;
			for (int j = i + 1; j < n; j++) {
				if (lcs[i][j] >= j - i) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
				else {

				}
			}
		}
		return dp[0];
	}
};