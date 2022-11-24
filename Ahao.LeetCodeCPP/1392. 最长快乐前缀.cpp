#include<vector>
#include <string>

using namespace std;


/*
1392. 最长快乐前缀
「快乐前缀」是在原字符串中既是 非空 前缀也是后缀（不包括原字符串自身）的字符串。

给你一个字符串 s，请你返回它的 最长快乐前缀。

如果不存在满足题意的前缀，则返回一个空字符串。
*/
class Solution {
public:
	string longestPrefix(string s) {
		int n = s.size();
		s = ' ' + s;
		vector<int> res(n + 1);

		for (int i = 2, j = 0; i <= n; i++)
		{
			while (j && s[i] != s[j + 1])
				j = res[j];
			if (s[i] == s[j + 1]) j++;
			res[i] = j;
		}
		return s.substr(1, res[n]);
	}
};