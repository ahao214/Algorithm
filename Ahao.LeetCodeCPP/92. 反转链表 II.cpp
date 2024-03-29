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
92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
*/
class Solution {
public:
	//1.先求出点的位置
	//2.将left和right之间的节点反转
	//3.头尾节点的交换
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left == right) return head;
		auto dummy = new ListNode(-1);
		dummy->next = head;
		auto a = dummy, d = dummy;
		for (int i = 0; i < left - 1; i++) a = a->next;
		for (int i = 0; i < right; i++) d = d->next;

		auto b = a->next, c = d->next;
		for (auto p = b, q = b->next; q != c;)
		{
			auto o = q->next;
			q->next = p;
			p = q, q = o;
		}
		b->next = c;
		a->next = d;
		return dummy->next;
	}
};



class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		//链表在right处断开
		ListNode* p = dummy;
		for (int i = 0; i < right; i++)
			p = p->next;
		ListNode* c = p->next;
		p->next = nullptr;

		//链表在left处断开
		p = dummy;
		for (int i = 0; i < left - 1; i++)
			p = p->next;
		ListNode* b = p->next;
		p->next = nullptr;

		b = reverseLinkedList(b);

		p = dummy;
		while (p->next)
			p = p->next;
		p->next = b;
		while (p->next)
			p = p->next;
		p->next = c;

		return dummy->next;
	}

	ListNode* reverseLinkedList(ListNode* head)
	{
		ListNode* last = nullptr;
		ListNode* cur = head;
		ListNode* nxt;
		while (cur)
		{
			nxt = cur->next;
			cur->next = last;
			last = cur;
			cur = nxt;
		}
		return last;
	}
};
