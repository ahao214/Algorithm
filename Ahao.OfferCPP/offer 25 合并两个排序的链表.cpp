#include<vector>

using namespace std;


/*
offer 25 合并两个排序的链表
*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1)return pHead2;
	else if (!pHead2)return pHead1;

	ListNode* pM = nullptr;
	if (pHead1->val < pHead2->val)
	{
		pM = pHead1;
		pM->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		pM = pHead2;
		pM->next = Merge(pHead1, pHead2->next);
	}
	return pM;
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};