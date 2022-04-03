#include <cstddef>
using namespace std;

#pragma region 29. 删除链表中重复的节点

/*
在一个排序的链表中，存在重复的节点，请删除该链表中重复的节点，重复的节点不保留。

数据范围
链表中节点 val 值取值范围 [0,100]。
链表长度 [0,100]。
*/

#pragma endregion


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* head) {
		ListNode* dummy = new ListNode(0), * p = dummy;
		dummy->next = head;
		while (p->next)
		{
			ListNode* q = p->next;
			while (q->next && q->next->val == q->val)
				q = q->next;
			if (q == p->next)
				p = p->next;
			else
				p->next = q->next;
		}
		return dummy->next;
	}
};