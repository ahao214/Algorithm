#include<vector>

using namespace std;


/*
offer 23 链表中环的入口节点
*/
ListNode* EntryNodeofLoop(ListNode* pHead) {
	if (!pHead)
		return nullptr;
	ListNode* fast = pHead, * slow = pHead;
	while (fast && slow) {
		fast = fast->next;
		slow = slow->next;
		if (fast)
			fast = fast->next;
		else
			return nullptr;
		if (fast = slow)
		{
			fast = pHead;
			while (fast && slow && fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
	}
	return nullptr;
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};