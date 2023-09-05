#include<vector>
#include <queue>

using namespace std;

/*
109. 有序链表转换二叉搜索树

给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。
*/


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};


class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		int n = 0;
		for (auto p = head; p; p = p->next)
			n++;
		if (n == 1) return new TreeNode(head->val);
		auto cur = head;
		for (int i = 0; i < n / 2 - 1; i++)
			cur = cur->next;
		auto root = new TreeNode(cur->next->val);
		root->right = sortedListToBST(cur->next->next);
		cur->next = NULL;
		root->left = sortedListToBST(head);
		return root;
	}
};