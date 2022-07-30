#include<vector>

using namespace std;



/*
offer 24 ·´×ªÁ´±í
*/
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pre = nullptr;
	ListNode* cur = pHead;
	ListNode* tmp;
	while (cur)
	{
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};