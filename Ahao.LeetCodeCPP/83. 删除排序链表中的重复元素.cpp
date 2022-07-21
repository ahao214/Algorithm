#include<vector>

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
	83. ɾ�����������е��ظ�Ԫ��
	����һ��������������ͷ head �� ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ ����������� ��
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p = head;
		//p��p����һ�ڵ㲻Ϊ��
		while (p && p->next)
		{
			ListNode* q = p->next;
			//��q�Ľڵ����p�Ľڵ㣬q����ƶ�
			while (q && q->val == p->val)
				q = q->next;
			//pָ������һ������ȵĽڵ�
			p->next = q;
			p = p->next;
		}
		return head;
	}
};
