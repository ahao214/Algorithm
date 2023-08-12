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




class Solution {
public:
	struct Status {
		int val;
		ListNode* ptr;
		bool operator < (const Status& rhs) const {
			return val > rhs.val;
		}
	};

	priority_queue <Status> q;

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		for (auto node : lists) {
			if (node) q.push({ node->val, node });
		}
		ListNode head, * tail = &head;
		while (!q.empty()) {
			auto f = q.top(); q.pop();
			tail->next = f.ptr;
			tail = tail->next;
			if (f.ptr->next) q.push({ f.ptr->next->val, f.ptr->next });
		}
		return head.next;
	}
};




class Solution {
public:
	ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
		if ((!a) || (!b)) return a ? a : b;
		ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
		while (aPtr && bPtr) {
			if (aPtr->val < bPtr->val) {
				tail->next = aPtr; aPtr = aPtr->next;
			}
			else {
				tail->next = bPtr; bPtr = bPtr->next;
			}
			tail = tail->next;
		}
		tail->next = (aPtr ? aPtr : bPtr);
		return head.next;
	}

	ListNode* merge(vector <ListNode*>& lists, int l, int r) {
		if (l == r) return lists[l];
		if (l > r) return nullptr;
		int mid = (l + r) >> 1;
		return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}
};



class Solution {
public:
	ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
		if ((!a) || (!b)) return a ? a : b;
		ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
		while (aPtr && bPtr) {
			if (aPtr->val < bPtr->val) {
				tail->next = aPtr; aPtr = aPtr->next;
			}
			else {
				tail->next = bPtr; bPtr = bPtr->next;
			}
			tail = tail->next;
		}
		tail->next = (aPtr ? aPtr : bPtr);
		return head.next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* ans = nullptr;
		for (size_t i = 0; i < lists.size(); ++i) {
			ans = mergeTwoLists(ans, lists[i]);
		}
		return ans;
	}
};
