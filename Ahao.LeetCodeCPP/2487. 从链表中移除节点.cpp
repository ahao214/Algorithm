#include<vector>
#include <stack>

using namespace std;


/*
2487. 从链表中移除节点

给你一个链表的头节点 head 。

移除每个右侧有一个更大数值的节点。

返回修改后链表的头节点 head 。
*/



class Solution {
public:
	ListNode* removeNodes(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		head->next = removeNodes(head->next);
		if (head->next != nullptr && head->val < head->next->val) {
			return head->next;
		}
		else {
			return head;
		}
	}
};




class Solution {
public:
	ListNode* removeNodes(ListNode* head) {
		stack<ListNode*> st;
		for (; head != nullptr; head = head->next) {
			st.push(head);
		}
		for (; !st.empty(); st.pop()) {
			if (head == nullptr || st.top()->val >= head->val) {
				st.top()->next = head;
				head = st.top();
			}
		}
		return head;
	}
};




class Solution {
public:
	ListNode* reverse(ListNode* head) {
		ListNode dummy;
		while (head != nullptr) {
			ListNode* p = head;
			head = head->next;
			p->next = dummy.next;
			dummy.next = p;
		}
		return dummy.next;
	}

	ListNode* removeNodes(ListNode* head) {
		head = reverse(head);
		for (ListNode* p = head; p->next != nullptr; ) {
			if (p->val > p->next->val) {
				p->next = p->next->next;
			}
			else {
				p = p->next;
			}
		}
		return reverse(head);
	}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};