#include<vector>
#include<stack>

using namespace std;


/*
offer 6 从尾到头打印链表
*/

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
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



