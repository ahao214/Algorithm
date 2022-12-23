#include<vector>
#include <string>
#include <stack>

using namespace std;


/*
402. 移掉 K 位数字
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
*/
class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<char> stk;
		for (auto x : num)
		{
			while (stk.size() && stk.top() > x && k)
			{
				stk.pop();
				k--;
			}
			stk.push(x);
		}
		//K还没有用完,从栈顶开始删除
		while (k--) stk.pop();

		string res;
		while (stk.size())
		{
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		int i = 0;
		//去掉前面的0
		while (i < res.size() && res[i] == '0') i++;
		if (i == res.size()) return "0";
		return res.substr(i);
	}
};
