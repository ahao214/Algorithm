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