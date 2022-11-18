using namespace std;



/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		auto cur = dummy;
		while (cur)
		{
			int s = 0;
			for (auto i = cur->next; i; i = i->next) s++;
			if (s < k) break;

			s = 1;
			auto a = cur->next, b = a->next;
			while (s < k)
			{
				auto c = b->next;
				b->next = a;
				a = b, b = c;
				s++;
			}
			cur->next->next = b;
			auto p = cur->next;
			cur->next = a;
			cur = p;
		}
		return dummy->next;
	}
};


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* start = dummy, * end = dummy;

		while (true) {
			for (int i = 0; i < k && end; i++) end = end->next;
			if (!end) break;
			ListNode* startNext = start->next;
			ListNode* endNext = end->next;

			end->next = nullptr;
			start->next = reverse(start->next);
			startNext->next = endNext;
			start = end = startNext;
		}
		return dummy->next;
	}

	ListNode* reverse(ListNode* head) {
		ListNode* cur = head, * pre = nullptr;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};