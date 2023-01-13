#include<string>
#include<unordered_set>

using namespace std;



/*
1763. 最长的美好子字符串
当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。

给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。
*/
class Solution {
public:
	bool check(string s)
	{
		unordered_set<char> hash;
		for (auto c : s)
			hash.insert(c);
		for (auto c : s)
			if (hash.count(c ^ 32) == 0)
				return false;
		return true;
	}
	string longestNiceSubstring(string s) {
		string res;
		for (int i = 0; i < s.size(); i++)
			for (int j = i; j < s.size(); j++)
			{
				string str = s.substr(i, j - i + 1);
				if (check(str) && res.size() < str.size())
					res = str;
			}
		return res;
	}
};




class Solution {
public:
	bool check(const string& s, int a, int b) {
		set<char> st;
		for (int i = a; i <= b; ++i) {
			st.insert(s[i]);
		}
		for (int i = a; i <= b; ++i) {
			char c = s[i];
			if (c <= 'z' && c >= 'a') {
				if (!st.count(c - 'a' + 'A')) return false;
			}
			else {
				if (!st.count(c - 'A' + 'a')) return false;
			}
		}
		return true;
	}
	string longestNiceSubstring(string s) {
		int n = s.size(), ml = 0, le = 0, ri = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (check(s, i, j)) {
					if (j - i > ml) {
						ml = j - i;
						le = i;
						ri = j;
					}
				}
			}
		}
		if (ml) {
			return s.substr(le, ri - le + 1);
		}
		else {
			return "";
		}
	}
};