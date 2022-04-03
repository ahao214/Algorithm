#include <cstddef>


#pragma region 36. 合并两个排序的链表

/*
输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。

数据范围
链表长度 [0,500]。
*/

#pragma endregion


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* merge(ListNode* l1, ListNode* l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode* res = nullptr;
		if (l1->val < l2->val)
		{
			res = l1;
			res->next = merge(l1->next, l2);
		}
		else
		{
			res = l2;
			res->next = merge(l1, l2->next);
		}
		return res;
	}
};