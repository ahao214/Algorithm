#include<string>
#include <unordered_map>

using namespace std;

/*
76. 最小覆盖子串
给你一个字符串  s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
*/

class Solution {
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


class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> hash;
		for (auto c : t) hash[c]++;
		int cnt = hash.size();

		string res;
		for (int i = 0, j = 0, c = 0; i < s.size(); i++)
		{
			if (hash[s[i]] == 1) c++;
			hash[s[i]]--;
			while (hash[s[j]] < 0) hash[s[j++]]++;
			if (c == cnt)
			{
				if (res.empty() || res.size() > i - j + 1)
					res = s.substr(j, i - j + 1);
			}
		}
		return res;
	}
};
