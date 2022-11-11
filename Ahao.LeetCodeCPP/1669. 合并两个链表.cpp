#include<vector>

using namespace std;




struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


/*
1669. �ϲ���������
������������ list1 �� list2 �����ǰ�����Ԫ�طֱ�Ϊ n ���� m ����

���㽫 list1 ���±�� a �� b ��ȫ���ڵ㶼ɾ��������list2 ���ڱ�ɾ���ڵ��λ�á�
*/
class Solution {
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		auto p = list1, q = list1;
		for (int i = 0; i < a - 1; i++)
			p = p->next;
		for (int i = 0; i < b + 1; i++)
			q = q->next;
		p->next = list2;
		while (list2->next) list2 = list2->next;
		list2->next = q;
		return list1;
	}
};
