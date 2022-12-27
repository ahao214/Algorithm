using namespace std;

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		//0 -> 1 -> 2 -> 3
		//pre  cur  next
		ListNode* pre = dummy, * cur = dummy->next;
		while (cur && cur->next) {
			ListNode* next = cur->next;
			pre->next = next;
			cur->next = next->next;
			next->next = cur;
			pre = cur;
			cur = cur->next;
		}
		return dummy->next;
	}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



/*
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		auto dummy = new ListNode(-1);
		dummy->next = head;

		for (auto p = dummy; p->next && p->next->next;)
		{
			auto a = p->next, b = a->next;
			p->next = b;
			a->next = b->next;
			b->next = a;
			p = a;
		}
		return dummy->next;
	}
};


/*
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		auto dummy = new ListNode(0);
		dummy->next = head;
		auto p = dummy;
		while (p && p->next && p->next->next)
		{
			auto a = p->next, b = a->next;
			p->next = b, a->next = b->next;
			b->next = a, p = a;
		}
		return dummy->next;
	}
};




/*
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* first = head, * second = head->next;
		first->next = swapPairs(second->next);
		second->next = first;
		return second;
	}
};