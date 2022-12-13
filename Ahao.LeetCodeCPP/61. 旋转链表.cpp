#include <cstddef>
using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};


/*
61. ��ת����
����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�
*/
class Solution {

public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	/*
	1����������β����
	2���ҵ��ֶε�(n - k % n)
	3���Ͽ����������µ�ͷ�ڵ�
	*/
	ListNode* rotateRight(ListNode* head, int k) {
		//�Կ������ж�
		if (!head) return nullptr;
		ListNode* cur = head;
		int n = 1;
		//�����������
		while (cur->next) cur = cur->next, n++;
		cur->next = head;

		for (int i = 0; i < n - k % n; i++)
		{
			cur = cur->next;
		}
		head = cur->next;
		cur->next = nullptr;

		return head;
	}
};



/*
61. ��ת����
����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�
*/
class Solution {
public:
	//1.k %= n
	//2.firstָ���ͷ������K��
	//3.second��firstͬʱ�����ߣ���first�ߵ�β����ʱ��ֹͣ
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return NULL;
		int n = 0;
		for (auto p = head; p; p = p->next)
			n++;

		k %= n;
		auto first = head, second = head;
		while (k--) first = first->next;
		while (first->next)
		{
			first = first->next;
			second = second->next;
		}

		first->next = head;
		head = second->next;
		second->next = NULL;
		return head;
	}
};