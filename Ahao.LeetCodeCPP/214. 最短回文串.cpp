#include<vector>
#include <string>

using namespace std;



/*
214. 最短回文串
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
*/
class Solution {
public:
	string shortestPalindrome(string s) {
		string raws = s;
		reverse(s.begin(), s.end());
		s = raws + '#' + s;
		int n = s.size();
		vector<int> nxt(n + 1, 0);
		for (int i = 2, j = 0; i <= n; i++)
		{
			while (j && s[j] != s[i - 1]) j = nxt[j];
			if (s[j] == s[i - 1]) j++;
			nxt[i] = j;
		}
		int res = nxt[n];
		string sup = raws.substr(res);
		reverse(sup.begin(), sup.end());
		return sup + raws;
	}
};
