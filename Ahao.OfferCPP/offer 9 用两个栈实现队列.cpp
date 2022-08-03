#include<vector>
#include<stack>

using namespace std;


/*
offer 9 ������ջʵ�ֶ���
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while (stack1.size())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        stack2.pop();
        while (stack2.size())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};