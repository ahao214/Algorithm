#include<vector>

using namespace std;

/*
143. 重排链表

给定一个单链表 L 的头节点 head ，单链表 L 表示为：
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
	void reorderList(ListNode* head) {
		if (head == nullptr) {
			return;
		}
		vector<ListNode*> vec;
		ListNode* node = head;
		while (node != nullptr) {
			vec.emplace_back(node);
			node = node->next;
		}
		int i = 0, j = vec.size() - 1;
		while (i < j) {
			vec[i]->next = vec[j];
			i++;
			if (i == j) {
				break;
			}
			vec[j]->next = vec[i];
			j--;
		}
		vec[i]->next = nullptr;
	}
};




class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode* mid = getMidNode(head);
		ListNode* next = reverse(mid->next);
		mid->next = nullptr;
		merge(head, next);
	}

	//合并
	void merge(ListNode* l1, ListNode* l2)
	{
		while (l1 && l2)
		{
			ListNode* n1 = l1->next, * n2 = l2->next;
			l1->next = l2, l2->next = n1;
			l1 = n1, l2 = n2;
		}
	}

	//获取中间结点
	ListNode* getMidNode(ListNode* head)
	{
		ListNode* slow = head, * fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	//翻转链表
	ListNode* reverse(ListNode* head)
	{
		ListNode* cur = head, * pre = nullptr;
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};