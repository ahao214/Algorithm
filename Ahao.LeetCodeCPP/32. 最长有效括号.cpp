using namespace std;
#include <string>
#include<stack>


/*
32. 最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，
找出最长有效（格式正确且连续）括号子串的长度。
*/

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		int ans = 0;
		for (int i = 0, start = -1; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				if (!stk.empty()) {
					stk.pop();
					if (!stk.empty()) {
						ans = max(ans, i - stk.top());
					}
					else {
						ans = max(ans, i - start);
					}
				}
				else {
					start = i;
				}
			}
		}
		return ans;
	}
};



class Solution {
public:
	int work(string s)
	{
		int res = 0;
		for (int i = 0, start = 0, cnt = 0; i < s.size(); i++)
		{
			if (s[i] == '(') cnt++;
			else
			{
				cnt--;
				if (!cnt) res = max(res, i - start + 1);
				else if (cnt < 0)
				{
					start = i + 1;
					cnt = 0;
				}
			}
		}
		return res;
	}

	int longestValidParentheses(string s) {
		int res = work(s);
		reverse(s.begin(), s.end());
		for (auto& c : s) c ^= 1; //左括号换成右括号 右括号换成左括号
		return max(res, work(s));
	}
};
