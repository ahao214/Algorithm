#include<vector>

using namespace std;


/*
offer 52 两个链表的第一个公共结点
*/

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* headA, ListNode* headB) {
		int len1 = GetLengthOfList(headA);
		int len2 = GetLengthOfList(headB);

		int def = 0;
		ListNode* pLong, * pShort;
		if (len1 > len2)
		{
			pLong = headA;
			pShort = headB;
			def = len1 - len2;
		}
		else
		{
			pLong = headB;
			pShort = headA;
			def = len2 - len1;
		}
		while (def)
		{
			pLong = pLong->next;
			def--;
		}
		while (pLong && pShort && pLong != pShort)
		{
			pLong = pLong->next;
			pShort = pShort->next;
		}
		return pLong;
	}

	int GetLengthOfList(ListNode* pHead)
	{
		ListNode* p = pHead;
		int len = 0;
		while (p)
		{
			len++;
			p = p->next;
		}
		return len;
	}
};