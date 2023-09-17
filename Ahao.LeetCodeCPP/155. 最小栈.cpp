#include<vector>
#include<stack>

using namespace std;


/*
155. ��Сջ

���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

push(x) ���� ��Ԫ�� x ����ջ�С�
pop() ���� ɾ��ջ����Ԫ�ء�
top() ���� ��ȡջ��Ԫ�ء�
getMin() ���� ����ջ�е���СԪ�ء�
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
