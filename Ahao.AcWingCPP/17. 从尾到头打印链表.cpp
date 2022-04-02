using namespace std;
#include<vector>
#include<stack>

#pragma region 17. 从尾到头打印链表

/*
输入一个链表的头结点，按照 从尾到头 的顺序返回节点的值。

返回的结果用数组存储。
*/

/*
思路：
1、定义一个栈，把链表里面的数据放入到栈中
2、从栈中依次获取栈顶的元素
*/

#pragma endregion

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        stack<int> stk;
        ListNode* p = head;
        while (p)
        {
            stk.push(p->val);
            p = p->next;
        }
        vector<int> res;
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};