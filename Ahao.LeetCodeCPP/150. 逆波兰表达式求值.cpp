#include<vector>
#include<string>
#include <stack>


using namespace std;



/*
150. 逆波兰表达式求值
*/
//时间O(N) 空间O(N)
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		for (string& token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				int b = stk.top();
				stk.pop();
				int a = stk.top();
				stk.pop();
				if (token == "+")
					stk.push(a + b);
				else if (token == "-")
					stk.push(a - b);
				else if (token == "*")
					stk.push(a * b);
				else
					stk.push(a / b);
			}
			else {
				stk.push(stoi(token));
			}
		}
		return stk.top();
	}
};