#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
	/*
	86. 分隔链表
	给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

	你应当 保留 两个分区中每个节点的初始相对位置。
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	int maximalRectangle(vector<vector<char>>& matrix) {
		ListNode* lh = new ListNode(0), * l = lh;
		ListNode* rh = new ListNode(0), * r = rh;
		for (ListNode* cur = head; cur; cur = cur->next)
		{
			if (cur->val < x) l = l->next = cur;
			else r = r->next = cur;
		}
		l->next = rh->next;
		r->next = nullptr;
		return lh->next;

	}
};


