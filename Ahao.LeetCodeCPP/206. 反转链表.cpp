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
206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;

		auto a = head, b = a->next;

		while (b)
		{
			//c临时保存b的下一个节点
			auto c = b->next;
			b->next = a;
			a = b, b = c;
		}
		head->next = NULL;
		return a;
	}
};




class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* last = nullptr;
		ListNode* cur = head;
		ListNode* nxt;

		while (cur != nullptr)
		{
			nxt = cur->next;
			cur->next = last;
			last = cur;
			cur = nxt;
		}
		return last;
	}
};
