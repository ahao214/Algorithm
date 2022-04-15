using namespace std;
#include<vector>
#include <queue>

class Solution {
	/*
	23. �ϲ�K����������
	����һ���������飬ÿ�������Ѿ����������С�

	���㽫��������ϲ���һ�����������У����غϲ��������
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