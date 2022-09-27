#include<vector>
#include<string>

using namespace std;





/*
1771. 由子序列构造的最长回文串的长度
给你两个字符串 word1 和 word2 ，请你按下述方法构造一个字符串：

从 word1 中选出某个 非空 子序列 subsequence1 。
从 word2 中选出某个 非空 子序列 subsequence2 。
连接两个子序列 subsequence1 + subsequence2 ，得到字符串。
返回可按上述方法构造的最长 回文串 的 长度 。如果无法构造回文串，返回 0 。

字符串 s 的一个 子序列 是通过从 s 中删除一些（也可能不删除）字符而不更改其余字符的顺序生成的字符串。

回文串 是正着读和反着读结果一致的字符串。
*/

const int N = 1010;
int f1[N][N], f2[N][N], f3[N][N];
class Solution {
public:
	void work(string& s, int f[][N])
	{
		int n = s.size();
		for (int len = 1; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1;
				if (len == 1) f[i][j] = 1;
				else
				{
					f[i][j] = max(f[i + 1][j], f[i][j - 1]);
					if (s[i] == s[j])
						f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
				}
			}
		}
	}

	int longestPalindrome(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		reverse(word2.begin(), word2.end());
		memset(f1, 0, sizeof f1);
		memset(f2, 0, sizeof f2);
		memset(f3, 0, sizeof f3);
		word1 = ' ' + word1, word2 = ' ' + word2;
		work(word1, f2), work(word2, f3);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				f1[i][j] = max(f1[i - 1][j], f1[i][j - 1]);
				if (word1[i] == word2[j])
					f1[i][j] = max(f1[i][j], f1[i - 1][j - 1] + 1);
			}
		}

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (f1[i][j])
					res = max(res, f1[i][j] * 2 + max(f2[i + 1][n], f3[j + 1][m]));
			}
		}
		return res;
	}
};
