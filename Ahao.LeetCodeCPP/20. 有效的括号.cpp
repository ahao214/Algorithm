using namespace std;
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>

class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, char> pairs = {
			{'(',')'},{'[',']'},{'{','}'}
		};
		stack<char> stk;
		for (int i = 0; i < s.length(); i++) {
			if (pairs.find(s[i]) != pairs.end()) {
				stk.push(pairs[s[i]]);
			}
			else {
				if (stk.empty() || stk.top() != s[i]) {
					return false;
				}
				stk.pop();
			}
		}
		return stk.empty();
	}
};


/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (auto c : s)
		{
			if (c == ')')
			{
				if (stk.empty() || stk.top() != '(') return false;
				stk.pop();
			}
			else if (c == ']')
			{
				if (stk.empty() || stk.top() != '[') return false;
				stk.pop();
			}
			else if (c == '}')
			{
				if (stk.empty() || stk.top() != '{') return false;
				stk.pop();
			}
			else
				stk.push(c);
		}
		return stk.empty();
	}
};
