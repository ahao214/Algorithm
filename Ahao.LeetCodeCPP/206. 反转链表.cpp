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
206. ��ת����
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;

		auto a = head, b = a->next;

		while (b)
		{
			//c��ʱ����b����һ���ڵ�
			auto c = b->next;
			b->next = a;
			a = b, b = c;
		}
		head->next = NULL;
		return a;
	}
};




class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* last = nullptr;
		ListNode* cur = head;
		ListNode* nxt;

		while (cur != nullptr)
		{
			nxt = cur->next;
			cur->next = last;
			last = cur;
			cur = nxt;
		}
		return last;
	}
};
