using namespace std;

#include<vector>
#include<string>

class Solution {
	/*
	65. 有效数字
	有效数字（按顺序）可以分成以下几个部分：

	一个 小数 或者 整数
	（可选）一个 'e' 或 'E' ，后面跟着一个 整数
	小数（按顺序）可以分成以下几个部分：

	（可选）一个符号字符（'+' 或 '-'）
	下述格式之一：
	至少一位数字，后面跟着一个点 '.'
	至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
	一个点 '.' ，后面跟着至少一位数字
	整数（按顺序）可以分成以下几个部分：

	（可选）一个符号字符（'+' 或 '-'）
	至少一位数字
	部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]

	部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]

	给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	bool isNumber(string s) {
		int idx = -1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'e' || s[i] == 'E')
			{
				if (idx == -1) idx = i;
				else
					return false;
			}
		}
		if (idx == -1) {
			return check(s, 0, s.length() - 1, false);
		}
		return check(s, 0, idx - 1, false) && check(s, idx + 1, s.length() - 1, true);
	}

	bool check(string& s, int start, int end, bool mustInt) {
		if (s[start] == '+' || s[start] == '-') start++;
		bool point = false, digit = false;
		for (int i = start; i <= end; i++)
		{
			if (s[i] == '.') {
				if (point || mustInt) return false;
				point = true;
			}
			else if (isdigit(s[i])) {
				digit = true;
			}
			else {
				return false;
			}
		}
		return digit;
	}
};
