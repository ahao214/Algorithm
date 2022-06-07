using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};



class Solution {
	/*
	61. ��ת����
	����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�
	*/
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