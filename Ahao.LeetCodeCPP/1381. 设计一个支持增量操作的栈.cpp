#include<vector>

using namespace std;


/*
1381. 设计一个支持增量操作的栈
请你设计一个支持下述操作的栈。

实现自定义栈类 CustomStack ：

CustomStack(int maxSize)：用 maxSize 初始化对象，maxSize 是栈中最多能容纳的元素数量，栈在增长到 maxSize 之后则不支持 push 操作。
void push(int x)：如果栈还未增长到 maxSize ，就将 x 添加到栈顶。
int pop()：弹出栈顶元素，并返回栈顶的值，或栈为空时返回 -1 。
void inc(int k, int val)：栈底的 k 个元素的值都增加 val 。如果栈中元素总数小于 k ，则栈中的所有元素都增加 val 。
*/
class Solution {
public:
    vector<int> stk;
    int top;
    void CustomStack(int maxSize) {
        stk = vector<int>(maxSize);
        top = 0;
    }

    void push(int x) {
        if (top == stk.size()) return;
        stk[top++] = x;
    }

    int pop() {
        if (!top) return -1;
        return stk[--top];
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < top; i++)
            stk[i] += val;
    }
};

