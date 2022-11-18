using namespace std;
#include<vector>
#include <queue>




/*
23. �ϲ�K����������
����һ���������飬ÿ�������Ѿ����������С�

���㽫��������ϲ���һ�����������У����غϲ��������
*/
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<pair<int, ListNode*>> heap;
		for (auto list : lists)
		{
			if (list) heap.push({ -list->val,list });
		}
		ListNode* dummy = new ListNode(-1);
		auto cur = dummy;
		while (heap.size())
		{
			auto t = heap.top();
			heap.pop();
			if (t.second->next) heap.push({ -t.second->next->val,t.second->next });

			cur->next = t.second;
			cur = cur->next;
		}
		cur->next = NULL;
		return dummy->next;
	}
};



class Solution {
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