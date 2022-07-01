#include<string>
#include <unordered_map>

using namespace std;


class Solution {
	/*
	76. 最小覆盖子串
	给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
	*/
public:
	/*
	Times:O(n)
	Space:O(n)
	*/
	string minWindow(string s, string t) {
		unordered_map<char, int> hs, ht;
		for (int i = 0; i < t.length(); i++) ht[t[i]]++;

		string ans;
		for (int i = 0, j = 0, cnt = 0; i < s.length(); i++)
		{
			if (++hs[s[i]] <= ht[s[i]]) cnt++;
			while (hs[s[j]] > ht[s[j]]) hs[s[j++]]--;
			if (cnt == t.length())
			{
				if (ans.empty() || ans.length() > i - j + 1)
				{
					ans = s.substr(j, i - j + 1);
				}
			}
		}
		return ans;
	}
};