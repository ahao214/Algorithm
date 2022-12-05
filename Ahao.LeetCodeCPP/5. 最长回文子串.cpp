using namespace std;

#include<string>

/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
*/
class Solution {
public:
	string longestPalindrome(string s) {
		string res = "";
		for (int i = 0; i < s.length(); i++) {
			//字符串长度为奇数
			int l = i - 1, r = i + 1;
			while (l >= 0 && r < s.length() && s[l] == s[r])
				l--, r++;
			if (res.length() < r - l - 1)
				res = s.substr(l + 1, r - l - 1);

			//字符串长度为偶数
			l = i, r = i + 1;
			while (l >= 0 && r < s.length() && s[l] == s[r])
				l--, r++;
			if (res.length() < r - l - 1)
				res = s.substr(l + 1, r - l - 1);
		}
		return res;
	}
};
