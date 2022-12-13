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
83. 删除排序链表中的重复元素
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
*/
class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p = head;
		//p和p的下一节点不为空
		while (p && p->next)
		{
			ListNode* q = p->next;
			//当q的节点等于p的节点，q向后移动
			while (q && q->val == p->val)
				q = q->next;
			//p指向后面第一个不相等的节点
			p->next = q;
			p = p->next;
		}
		return head;
	}
};




/*
83. 删除排序链表中的重复元素
给定一个已排序的链表的头 head ，
删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		auto cur = head;
		while (cur)
		{
			if (cur->next && cur->next->val == cur->val)
				cur->next = cur->next->next;
			else
				cur = cur->next;
		}
		return head;
	}
};
