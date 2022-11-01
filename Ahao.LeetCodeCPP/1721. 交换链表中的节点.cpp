#include<vector>

using namespace std;


/*
1721. ���������еĽڵ�
���������ͷ�ڵ� head ��һ������ k ��

���� ���������� k ���ڵ�͵����� k ���ڵ��ֵ�󣬷��������ͷ�ڵ㣨���� �� 1 ��ʼ��������
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
public:
	ListNode* swapNodes(ListNode* head, int k) {
		vector<int> res;
		for (auto p = head; p; p = p->next)
			res.push_back(p->val);
		swap(res[k - 1], res[res.size() - k]);
		head = new ListNode(res[0]);
		auto cur = head;
		for (int i = 1; i < res.size(); i++)
			cur = cur->next = new ListNode(res[i]);
		return head;
	}


	ListNode* swapNodes(ListNode* head, int k) {
		auto dummy = new ListNode(-1);
		dummy->next = head;
		int n = 0;
		for (auto p = dummy; p; p = p->next)n++;
		k++;
		auto a = dummy;
		for (int i = 0; i < k - 2; i++) a = a->next;
		auto b = dummy;
		for (int i = 0; i < n - k; i++) b = b->next;

		if (a == b) return dummy->next;

		auto pa = a->next, qa = pa->next;
		auto pb = b->next, qb = pb->next;
		if (a->next == b)
		{
			a->next = qa, qa->next = pa;
			pa->next = qb;
			return dummy->next;
		}
		else if (b->next == a)
		{
			b->next = qb, qb->next = pb;
			pb->next = qa;
			return dummy->next;
		}
		pa->next = qb, b->next = pa;
		pb->next = qa, a->next = pb;

		return dummy->next;
	}
};