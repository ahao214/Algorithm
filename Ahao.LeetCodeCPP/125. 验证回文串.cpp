#include<vector>
#include <string>

using namespace std;


/*
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
*/
class Solution {
public:
	bool check(char c)
	{
		return c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
	}
	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			while (i < j && !check(s[i])) i++;
			while (i < j && !check(s[j])) j--;
			if (s[i] != s[j] && s[i] != (s[j] ^ 32)) return false;
		}
		return true;
	}
};

