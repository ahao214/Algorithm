#include<vector>

using namespace std;


/*
148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
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
	ListNode* sortList(ListNode* head) {
		int n = 0;
		for (auto p = head; p; p = p->next) n++;
		auto dummy = new ListNode(-1);
		dummy->next = head;

		for (int i = 1; i < n; i *= 2)
		{
			auto cur = dummy;
			for (int j = 0; j + i < n; j += i * 2)
			{
				auto left = cur->next, right = cur->next;
				for (int k = 0; k < i; k++) right = right->next;
				int l = 0, r = 0;
				while (l < i && r < i && right)
					if (left->val <= right->val)
					{
						cur->next = left;
						cur = left;
						left = left->next;
						l++;
					}
					else
					{
						cur->next = right;
						cur = right;
						right = right->next;
						r++;
					}
				while (l < i)
				{
					cur->next = left;
					cur = left;
					left = left->next;
					l++;
				}
				while (r < i && right)
				{
					cur->next = right;
					cur = right;
					right = right->next;
					r++;
				}

				cur->next = right;
			}
		}
		return dummy->next;
	}
};
