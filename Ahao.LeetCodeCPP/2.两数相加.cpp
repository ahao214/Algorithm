struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	/*
	2. 两数相加
	给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

	请你将两个数相加，并以相同形式返回一个表示和的链表。

	你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
	*/
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//虚拟头节点
		ListNode* dummy = new ListNode(0), * cur = dummy;
		int sum = 0;
		while (l1 || l2 || sum) {
			if (l1) sum += l1->val, l1 = l1->next;
			if (l2) sum += l2->val, l2 = l2->next;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			sum /= 10;
		}
		return dummy->next;
	}
};
