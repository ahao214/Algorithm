#include<vector>

using namespace std;




struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


/*
1669. 合并两个链表
给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。
*/
class Solution {
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		auto p = list1, q = list1;
		for (int i = 0; i < a - 1; i++)
			p = p->next;
		for (int i = 0; i < b + 1; i++)
			q = q->next;
		p->next = list2;
		while (list2->next) list2 = list2->next;
		list2->next = q;
		return list1;
	}
};
