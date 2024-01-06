#include<vector>

using namespace std;


/*
2807. �������в������Լ��

����һ�������ͷ head ��ÿ��������һ������ֵ��

�����ڽ��֮�䣬�������һ���µĽ�㣬���ֵΪ���������ڽ��ֵ�� ���Լ�� ��

���㷵�ز���֮�������

�������� ���Լ�� �ǿ��Ա��������������������������
*/

class Solution {
public:
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		ListNode* node = head;
		while (node->next) {
			node->next = new ListNode(__gcd(node->val, node->next->val), node->next);
			node = node->next->next;
		}
		return head;
	}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
