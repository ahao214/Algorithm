#include<vector>
#include <unordered_map>

using namespace std;



/*
1171. 从链表中删去总和值为零的连续节点

给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

删除完毕后，请你返回最终结果链表的头节点。



你可以返回任何满足题目要求的答案。

（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）
*/



struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        unordered_map<int, ListNode*> seen;
        for (ListNode* node = dummy; node; node = node->next) {
            prefix += node->val;
            seen[prefix] = node;
        }
        prefix = 0;
        for (ListNode* node = dummy; node; node = node->next) {
            prefix += node->val;
            node->next = seen[prefix]->next;
        }
        return dummy->next;
    }
};
