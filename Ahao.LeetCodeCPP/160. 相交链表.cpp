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
160. �ཻ����
���������������ͷ�ڵ� headA �� headB ��
�����ҳ������������������ཻ����ʼ�ڵ㡣
����������������ཻ�ڵ㣬���� null ��
*/
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		auto a = headA, b = headB;
		while (a != b)
		{
			if (a) a = a->next;
			else a = headB;
			if (b) b = b->next;
			else b = headA;
		}
		return a;
	}
};