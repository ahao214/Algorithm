using namespace std;

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* dummy = new ListNode(0), * cur = dummy;
		while (list1 && list2) {
			if (list1->val <= list2->val) {
				cur->next = new ListNode(list1->val);
				list1 = list1->next;
			}
			else {
				cur->next = new ListNode(list2->val);
				list2 = list2->next;
			}
			cur = cur->next;
		}
		cur->next = list1 ? list1 : list2;
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