#include<vector>
#include<string>

using namespace std;


/*
1957. 删除字符使字符串变好
一个字符串如果没有 三个连续 相同字符，那么它就是一个 好字符串 。

给你一个字符串 s ，请你从 s 删除 最少 的字符，使它变成一个 好字符串 。

请你返回删除后的字符串。题目数据保证答案总是 唯一的 。
*/
class Solution {
public:
	string makeFancyString(string s) {
		string res;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i + 1;
			while (j < s.size() && s[j] == s[i])
				j++;
			for (int k = 0; k < 2 && k < j - i; k++)
				res += s[i];
			i = j - 1;
		}
		return res;
	}
};



