#include <cstddef>


#pragma region 36. �ϲ��������������

/*
����������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ��յ�������ġ�

���ݷ�Χ
������ [0,500]��
*/

#pragma endregion


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* merge(ListNode* l1, ListNode* l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode* res = nullptr;
		if (l1->val < l2->val)
		{
			res = l1;
			res->next = merge(l1->next, l2);
		}
		else
		{
			res = l2;
			res->next = merge(l1, l2->next);
		}
		return res;
	}
};