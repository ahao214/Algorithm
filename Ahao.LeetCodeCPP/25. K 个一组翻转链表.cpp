using namespace std;



/*
25. K ��һ�鷭ת����
����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������

k ��һ��������������ֵС�ڻ��������ĳ��ȡ�

����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

���ף�

��������һ��ֻʹ�ó�������ռ���㷨�������������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����
*/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		auto cur = dummy;
		while (cur)
		{
			int s = 0;
			for (auto i = cur->next; i; i = i->next) s++;
			if (s < k) break;

			s = 1;
			auto a = cur->next, b = a->next;
			while (s < k)
			{
				auto c = b->next;
				b->next = a;
				a = b, b = c;
				s++;
			}
			cur->next->next = b;
			auto p = cur->next;
			cur->next = a;
			cur = p;
		}
		return dummy->next;
	}
};


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* start = dummy, * end = dummy;

		while (true) {
			for (int i = 0; i < k && end; i++) end = end->next;
			if (!end) break;
			ListNode* startNext = start->next;
			ListNode* endNext = end->next;

			end->next = nullptr;
			start->next = reverse(start->next);
			startNext->next = endNext;
			start = end = startNext;
		}
		return dummy->next;
	}

	ListNode* reverse(ListNode* head) {
		ListNode* cur = head, * pre = nullptr;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};