#include<vector>
#include <string>
#include <unordered_set>

using namespace std;


/*
1456. 定长子串中元音的最大数目
给你字符串 s 和整数 k 。

请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。

英文中的 元音字母 为（a, e, i, o, u）。
*/
class Solution {
public:
	int maxVowels(string s, int k) {
		int res = 0;
		unordered_set<char> S({ 'a','e','i','o','u' });
		for (int i = 0, cnt = 0; i < s.size(); i++)
		{
			cnt += S.count(s[i]);
			if (i >= k) cnt -= S.count(s[i - k]);
			if (i >= k - 1) res = max(res, cnt);
		}
		return res;
	}
};