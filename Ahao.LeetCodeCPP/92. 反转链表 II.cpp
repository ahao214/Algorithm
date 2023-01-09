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
92. ��ת���� II
���㵥�����ͷָ�� head ���������� left �� right ������ left <= right ��
���㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת������� ��
*/
class Solution {
public:
	//1.��������λ��
	//2.��left��right֮��Ľڵ㷴ת
	//3.ͷβ�ڵ�Ľ���
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

		//������right���Ͽ�
		ListNode* p = dummy;
		for (int i = 0; i < right; i++)
			p = p->next;
		ListNode* c = p->next;
		p->next = nullptr;

		//������left���Ͽ�
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
