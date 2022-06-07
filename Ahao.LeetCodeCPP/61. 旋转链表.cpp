using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};



class Solution {
	/*
	61. 旋转链表
	给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	/*
	1、将链表首尾连接
	2、找到分段点(n - k % n)
	3、断开链表，返回新的头节点
	*/
	ListNode* rotateRight(ListNode* head, int k) {
		//对空链表判断
		if (!head) return nullptr;
		ListNode* cur = head;
		int n = 1;
		//计算链表个数
		while (cur->next) cur = cur->next, n++;
		cur->next = head;

		for (int i = 0; i < n - k % n; i++)
		{
			cur = cur->next;
		}
		head = cur->next;
		cur->next = nullptr;

		return head;
	}

};