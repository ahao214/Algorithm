#include<vector>

using namespace std;

/*
147. 对链表进行插入排序
*/
//时间O(N……2) 空间O(1)

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(0), * cur = head;
		while (cur) {
			ListNode* prev = dummy, * next = cur->next;
			while (prev->next && prev->next->val <= cur->val) {
				prev = prev->next;
			}
			cur->next = prev->next;
			prev->next = cur;
			cur = next;
		}
		return dummy->next;
	}
};
