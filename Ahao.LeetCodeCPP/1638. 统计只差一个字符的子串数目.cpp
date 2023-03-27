#include<vector>
#include<string>

using namespace std;



/*
1638. 统计只差一个字符的子串数目

给你两个字符串 s 和 t ，请你找出 s 中的非空子串的数目，这些子串满足替换 一个不同字符 以后，是 t 串的子串。换言之，请你找到 s 和 t 串中 恰好 只有一个字符不同的子字符串对的数目。

比方说， "computer" and "computation" 只有一个字符不同： 'e'/'a' ，所以这一对子字符串会给答案加 1 。

请你返回满足上述条件的不同子字符串对数目。

一个 子字符串 是一个字符串中连续的字符。
*/
class Solution {
	int dp1[105][105];
	int dp2[105][105];
public:
	int countSubstrings(string s, string t) {
		int m = s.size();
		int n = t.size();
		s = "#" + s + "#";
		t = "#" + t + "#";

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (s[i] == t[j])
					dp1[i][j] = dp1[i - 1][j - 1] + 1;
				else
					dp1[i][j] = 0;
			}

		for (int i = m; i >= 1; i--)
			for (int j = n; j >= 1; j--)
			{
				if (s[i] == t[j])
					dp2[i][j] = dp2[i + 1][j + 1] + 1;
				else
					dp2[i][j] = 0;
			}

		int res = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[i] != t[j])
					res += (dp1[i - 1][j - 1] + 1) * (dp2[i + 1][j + 1] + 1);
			}
		}
		return res;
	}
};


class Solution {
public:
	int countSubstrings(string s, string t) {
		int m = s.size(), n = t.size();
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int diff = 0;
				for (int k = 0; i + k < m && j + k < n; k++) {
					diff += s[i + k] == t[j + k] ? 0 : 1;
					if (diff > 1) {
						break;
					}
					else if (diff == 1) {
						ans++;
					}
				}
			}
		}
		return ans;
	}
};

