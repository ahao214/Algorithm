﻿using namespace std;
#include<string>

/*
1616. 分割两个字符串得到回文串

难度：中等

给你两个字符串 a 和 b ，它们长度相同。请你选择一个下标，将两个字符串都在 相同的下标 分割开。由 a 可以得到两个字符串： aprefix 和 asuffix ，满足 a = aprefix + asuffix ，同理，由 b 可以得到两个字符串 bprefix 和 bsuffix ，满足 b = bprefix + bsuffix 。请你判断 aprefix + bsuffix 或者 bprefix + asuffix 能否构成回文串。

当你将一个字符串 s 分割成 sprefix 和 ssuffix 时， ssuffix 或者 sprefix 可以为空。比方说， s = "abc" 那么 "" + "abc" ， "a" + "bc" ， "ab" + "c" 和 "abc" + "" 都是合法分割。

如果 能构成回文字符串 ，那么请返回 true，否则返回 false 。
*/



class Solution {
public:
	bool checkPalindromeFormation(string a, string b) {
		return check(a, b) || check(b, a);
	}

	bool check(string& a, string& b)
	{
		int i = 0, j = a.size() - 1;
		while (i <= j && a[i] == b[j])
		{
			i++;
			j--;
		}
		if (i > j)
			return true;
		return isPalindrome(a.substr(i, j - i + 1)) || isPalindrome(b.substr(i, j - i + 1));
	}

	bool isPalindrome(string s)
	{
		int i = 0, j = s.size() - 1;
		while (i < j && s[i] == s[j])
		{
			i++;
			j--;
		}
		return i >= j;
	}
};


//双指针
class Solution {
public:
	bool checkSelfPalindrome(const string& a, int left, int right) {
		while (left < right && a[left] == a[right]) {
			left++;
			right--;
		}
		return left >= right;
	}

	bool checkConcatenation(const string& a, const string& b) {
		int n = a.size();
		int left = 0, right = n - 1;
		while (left < right && a[left] == b[right]) {
			left++;
			right--;
		}
		if (left >= right) {
			return true;
		}
		return checkSelfPalindrome(a, left, right) || checkSelfPalindrome(b, left, right);
	}

	bool checkPalindromeFormation(string a, string b) {
		return checkConcatenation(a, b) || checkConcatenation(b, a);
	}
};
