#include<vector>

using namespace std;



/*
offer 22 链表中倒数第k个节点
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* pHead, int k) {
	ListNode* p = pHead;
	int count = 0;
	while (p) {
		++count;
		p = p->next;
	}
	if (k > count) {
		return nullptr;
	}
	p = pHead;
	for (int i = 0; i < count - k; i++) {
		p = p->next;
	}
	return p;
};