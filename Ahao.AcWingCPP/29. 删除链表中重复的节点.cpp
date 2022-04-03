#include <cstddef>
using namespace std;

#pragma region 29. ɾ���������ظ��Ľڵ�

/*
��һ������������У������ظ��Ľڵ㣬��ɾ�����������ظ��Ľڵ㣬�ظ��Ľڵ㲻������

���ݷ�Χ
�����нڵ� val ֵȡֵ��Χ [0,100]��
������ [0,100]��
*/

#pragma endregion


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* head) {
		ListNode* dummy = new ListNode(0), * p = dummy;
		dummy->next = head;
		while (p->next)
		{
			ListNode* q = p->next;
			while (q->next && q->next->val == q->val)
				q = q->next;
			if (q == p->next)
				p = p->next;
			else
				p->next = q->next;
		}
		return dummy->next;
	}
};