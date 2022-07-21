#include<vector>

using namespace std;


class Solution {
	/*
	82. ɾ�����������е��ظ�Ԫ�� II
	����һ��������������ͷ head �� ɾ��ԭʼ�����������ظ����ֵĽڵ㣬ֻ���²�ͬ������ ������ ����������� ��
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	ListNode* deleteDuplicates(ListNode* head) {
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
				//ֱ��������ͬ�Ľڵ�
				p->next = q->next;
		}
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