using namespace std;
#include<vector>
#include<stack>

#pragma region 17. ��β��ͷ��ӡ����

/*
����һ�������ͷ��㣬���� ��β��ͷ ��˳�򷵻ؽڵ��ֵ��

���صĽ��������洢��
*/

/*
˼·��
1������һ��ջ����������������ݷ��뵽ջ��
2����ջ�����λ�ȡջ����Ԫ��
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