#include<vector>
#include <string>

using namespace std;




/*
680. 验证回文字符串 Ⅱ
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
*/
class Solution {
public:
	bool isValid(string s, int i, int j)
	{
		while (i < j)
		{
			if (s[i] != s[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	bool validPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (s[i] != s[j])
			{
				return (isValid(s, i, j - 1) || isValid(s, i + 1, j));
			}
			i++;
			j--;
		}
		return true;
	}
};
