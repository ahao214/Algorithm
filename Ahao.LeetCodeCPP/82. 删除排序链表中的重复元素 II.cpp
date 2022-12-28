#include<vector>

using namespace std;

/*
82. 删除排序链表中的重复元素 II
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/
class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode(0), * p = dummy;
		dummy->next = head;
		while (p->next)
		{
			ListNode* q = p->next;
			while (q->next && q->next->val == q->val)
				q = q->next;
			if (q == p->next)
				p = p->next;
			else
				//直接跳过相同的节点
				p->next = q->next;
		}
		return dummy->next;
	}
};



struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
82. 删除排序链表中的重复元素 II
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode dummy(0, head);
		ListNode* prev = &dummy;
		while (head)
		{
			if (head->next && head->val == head->next->val)
			{
				while (head->next && head->val == head->next->val)
				{
					head = head->next;
				}
				prev->next = head->next;
			}
			else
			{
				prev = head;
			}
			head = head->next;
		}
		return dummy.next;
	}
};