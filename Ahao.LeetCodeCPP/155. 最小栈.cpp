#include<vector>
#include<stack>

using namespace std;


/*
155. 最小栈

设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
*/
class Solution {
public:
    stack<int> stackValue;
    stack<int> stackMin;
    void MinStack() {
        stackMin.push(INT_MAX);
    }

    void push(int val) {
        stackValue.push(val);
        if (stackMin.empty() || stackMin.top() >= val)
            stackMin.push(val);
    }

    void pop() {
        if (!stackMin.empty() && stackMin.top() == stackValue.top())
            stackMin.pop();
        stackValue.pop();
    }

    int top() {
        return stackValue.top();
    }

    int getMin() {
        return stackMin.top();
    }
};




class Solution {
public:
    stack<int> stk, f;
    void MinStack() {

    }

    void push(int val) {
        stk.push(val);
        if (f.empty() || f.top() >= val)
            f.push(val);
    }

    void pop() {
        if (stk.top() <= f.top())
            f.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return f.top();
    }
};




class MinStack {
    stack<pair<int, int>> stk;
public:
    MinStack() {

    }

    void push(int val) {
        stk.push({ val,min(val,getMin()) });
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return !stk.empty() ? stk.top().second : INT_MAX;
    }
};
