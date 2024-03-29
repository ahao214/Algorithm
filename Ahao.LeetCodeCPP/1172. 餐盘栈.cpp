#include<vector>
#include<set>

using namespace std;


/*
1172. 餐盘栈

我们把无限数量 ∞ 的栈排成一行，按从左到右的次序从 0 开始编号。每个栈的的最大容量 capacity 都相同。

实现一个叫「餐盘」的类 DinnerPlates：

DinnerPlates(int capacity) - 给出栈的最大容量 capacity。
void push(int val) - 将给出的正整数 val 推入 从左往右第一个 没有满的栈。
int pop() - 返回 从右往左第一个 非空栈顶部的值，并将其从栈中删除；如果所有的栈都是空的，请返回 -1。
int popAtStack(int index) - 返回编号 index 的栈顶部的值，并将其从栈中删除；如果编号 index 的栈是空的，请返回 -1。
*/

class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (poppedPos.empty()) {
            int pos = stk.size();
            stk.emplace_back(val);
            if (pos % capacity == 0) {
                top.emplace_back(0);
            }
            else {
                top.back()++;
            }
        }
        else {
            int pos = *poppedPos.begin();
            poppedPos.erase(pos);
            stk[pos] = val;
            int index = pos / capacity;
            top[index]++;
        }
    }

    int pop() {
        while (!stk.empty() && poppedPos.count(stk.size() - 1)) {
            stk.pop_back();
            int pos = *poppedPos.rbegin();
            poppedPos.erase(pos);
            if (pos % capacity == 0) {
                top.pop_back();
            }
        }
        if (stk.empty()) {
            return -1;
        }
        else {
            int pos = stk.size() - 1;
            int val = stk.back();
            stk.pop_back();
            if (pos % capacity == 0) {
                top.pop_back();
            }
            else {
                top.back() = top.size() - 2;
            }
            return val;
        }
    }

    int popAtStack(int index) {
        if (index >= top.size()) {
            return -1;
        }
        int stackTop = top[index];
        if (stackTop < 0) {
            return -1;
        }
        top[index]--;
        int pos = index * capacity + stackTop;
        poppedPos.emplace(pos);
        return stk[pos];
    }
private:
    int capacity;
    vector<int> stk;
    vector<int> top;
    set<int> poppedPos;
};
