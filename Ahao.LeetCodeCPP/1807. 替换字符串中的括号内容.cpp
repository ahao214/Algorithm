#include<vector>
#include<string>
#include <unordered_map>

using namespace std;


/*
1807. 替换字符串中的括号内容
给你一个字符串 s ，它包含一些括号对，每个括号中包含一个 非空 的键。

比方说，字符串 "(name)is(age)yearsold" 中，有 两个 括号对，分别包含键 "name" 和 "age" 。
你知道许多键对应的值，这些关系由二维字符串数组 knowledge 表示，其中 knowledge[i] = [keyi, valuei] ，表示键 keyi 对应的值为 valuei 。

你需要替换 所有 的括号对。当你替换一个括号对，且它包含的键为 keyi 时，你需要：

将 keyi 和括号用对应的值 valuei 替换。
如果从 knowledge 中无法得知某个键对应的值，你需要将 keyi 和括号用问号 "?" 替换（不需要引号）。
knowledge 中每个键最多只会出现一次。s 中不会有嵌套的括号。

请你返回替换 所有 括号对后的结果字符串。
*/
class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge) {
		unordered_map<string, string> hash;
		for (auto& e : knowledge) hash[e[0]] = e[1];
		string res;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '(') res += s[i];
			else
			{
				string key;
				int j = i + 1;
				while (s[j] != ')') key += s[j++];
				i = j;
				if (hash.count(key)) res += hash[key];
				else res += '?';
			}
		}
		return res;
	}
};
