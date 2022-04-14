using namespace std;


struct  ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
	/*
	19. 删除链表的倒数第 N 个结点
	给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
	*/
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//虚拟头节点
		ListNode* dummy = new ListNode(0);
		ListNode* slow = dummy, * fast = dummy;
		dummy->next = head;
		for (int i = 0; i < n; i++) {
			fast = fast->next;
		}
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		slow->next = slow->next->next;
		return dummy->next;
	}
};
