using namespace std;
#include<string>
#include<vector>


class Solution {
	/*
	44. 通配符匹配
	给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

	'?' 可以匹配任何单个字符。
	'*' 可以匹配任意字符串（包括空字符串）。
	两个字符串完全匹配才算匹配成功。

	说明:

	s 可能为空，且只包含从 a-z 的小写字母。
	p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
	*/
public:
	bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
		s = ' ' + s, p = ' ' + p;
		vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
		f[0][0] = true;

		for (int i = 0; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (p[j] != '*')
				{
					f[i][j] = i && j && f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
				}
				else
				{
					f[i][j] = (j && f[i][j - 1]) || (i && f[i - 1][j]);
				}
			}
		}
		return f[n][m];
	}
};
