using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	/*
	19. ɾ������ĵ����� N �����
	����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
	*/
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//����ͷ�ڵ�
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
