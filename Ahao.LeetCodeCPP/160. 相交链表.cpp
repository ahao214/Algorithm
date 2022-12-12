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
160. 相交链表
给你两个单链表的头节点 headA 和 headB ，
请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
*/
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		auto a = headA, b = headB;
		while (a != b)
		{
			if (a) a = a->next;
			else a = headB;
			if (b) b = b->next;
			else b = headA;
		}
		return a;
	}
};