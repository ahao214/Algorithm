#include<vector>
#include<stack>

using namespace std;


/*
offer 30 °üº¬minº¯ÊýµÄÕ»
*/
class Solution {
public:
	void push(int value) {
		stk.push(value);
		if (stk_min.empty() || value < stk_min.top()) {
			stk_min.push(value);
		}
		else {
			stk_min.push(stk_min.top());
		}
	}
	void pop() {
		stk.pop();
		stk_min.pop();
	}
	int top() {
		return stk.top();
	}
	int min() {
		return stk_min.top();
	}
private:
	stack<int> stk;
	stack<int> stk_min;
};