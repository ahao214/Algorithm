struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	/*
	2. �������
	�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

	���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

	����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
	*/
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//����ͷ�ڵ�
		ListNode* dummy = new ListNode(0), * cur = dummy;
		int sum = 0;
		while (l1 || l2 || sum) {
			if (l1) sum += l1->val, l1 = l1->next;
			if (l2) sum += l2->val, l2 = l2->next;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			sum /= 10;
		}
		return dummy->next;
	}
};
