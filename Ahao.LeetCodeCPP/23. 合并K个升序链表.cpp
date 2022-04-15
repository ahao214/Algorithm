using namespace std;
#include<vector>
#include <queue>

class Solution {
	/*
	23. 合并K个升序链表
	给你一个链表数组，每个链表都已经按升序排列。

	请你将所有链表合并到一个升序链表中，返回合并后的链表。
	*/
public:
	struct Cmp {
		bool operator() (ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i]) heap.push(lists[i]);
		}
		ListNode* dummy = new ListNode(0), * cur = dummy;
		while (!heap.empty()) {
			ListNode* top = heap.top();
			heap.pop();
			cur = cur->next = top;
			if (top->next)
				heap.push(top->next);
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