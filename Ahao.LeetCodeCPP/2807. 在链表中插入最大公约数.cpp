#include<vector>

using namespace std;


/*
2807. 在链表中插入最大公约数

给你一个链表的头 head ，每个结点包含一个整数值。

在相邻结点之间，请你插入一个新的结点，结点值为这两个相邻结点值的 最大公约数 。

请你返回插入之后的链表。

两个数的 最大公约数 是可以被两个数字整除的最大正整数。
*/

class Solution {
public:
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		ListNode* node = head;
		while (node->next) {
			node->next = new ListNode(__gcd(node->val, node->next->val), node->next);
			node = node->next->next;
		}
		return head;
	}
};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
