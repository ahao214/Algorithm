#include<vector>
#include <string>

using namespace std;


/*
1249. 移除无效的括号
给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
*/
class Solution {
public:
	string helper(string s, char open, char close)
	{
		int cnt = 0;
		string res;
		for (auto c : s)
		{
			if (c == open)
			{
				cnt++;
			}
			if (c == close)
			{
				if (cnt == 0)
				{
					continue;
				}
				cnt--;
			}
			res += c;
		}
		return res;
	}

	string minRemoveToMakeValid(string s) {
		string res;
		res = helper(s, '(', ')');
		reverse(res.begin(), res.end());
		res = helper(res, ')', '(');
		reverse(res.begin(), res.end());
		return res;
	}
};