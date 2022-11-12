#include<vector>

using namespace std;



/*
2181. 合并零之间的节点
给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。

对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0 。

返回修改后链表的头节点 head 。
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
	ListNode* mergeNodes(ListNode* head) {
		ListNode* now = head;
		while (now != NULL) {
			if (now->val == 0) {
				now = now->next;
				continue;
			}
			ListNode* nxt = now->next;
			if (nxt->val != 0) {
				now->val += nxt->val;
				now->next = nxt->next;
			}
			else {
				now = now->next;
			}
		}
		now = head->next;
		while (now != NULL) {
			ListNode* nxt = now->next;
			if (nxt->val == 0)
				now->next = nxt->next;
			now = now->next;
		}
		return head->next;
	}


public:
	ListNode* mergeNodes(ListNode* head) {
		head = head->next;
		int sum = 0;
		vector<int> num;
		while (head != NULL)
		{
			if (head->val == 0)
			{
				num.push_back(sum);
				sum = 0;
			}
			else
			{
				sum += head->val;
			}
			head = head->next;
		}

		ListNode* ret, * cur;
		ret = cur = new ListNode(num[0]);
		int m = num.size();
		for (int i = 1; i < m; i++)
		{
			ListNode* node = new ListNode(num[i]);
			cur->next = node;
			cur = cur->next;
		}
		return ret;
	}
};