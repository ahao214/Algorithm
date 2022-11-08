#include<vector>
#include <string>
#include <set>

using namespace std;


/*
1704. 判断字符串的两半是否相似
给你一个偶数长度的字符串 s 。将其拆分成长度相同的两半，前一半为 a ，后一半为 b 。

两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。注意，s 可能同时含有大写和小写字母。

如果 a 和 b 相似，返回 true ；否则，返回 false 。
*/
class Solution {
public:
	int count(string s)
	{
		int res = 0;
		set<char> S({ 'a','e','i','o','u' });
		for (auto c : s)
		{
			auto x = tolower(c);
			if (S.count(x))
				res++;
		}
		return res;
	}

	bool halvesAreAlike(string s) {
		int n = s.size() / 2;
		return count(s.substr(0, n)) == count(s.substr(n));
	}
};
