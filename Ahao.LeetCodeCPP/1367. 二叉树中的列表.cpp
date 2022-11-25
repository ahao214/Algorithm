#include<vector>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
1367. 二叉树中的列表
给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。

如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一
对应以 head 为首的链表中每个节点的值，那么请你返回 True ，
否则返回 False 。

一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
*/
class Solution {
public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (dfs(head, root)) return true;

		if (!root) return false;
		//枚举起点
		return isSubPath(head, root->left) || isSubPath(head, root->right);
	}

	bool dfs(ListNode* cur, TreeNode* root)
	{
		if (!cur) return true;
		if (!root) return false;

		if (cur->val != root->val) return false;

		return dfs(cur->next, root->left) || dfs(cur->next, root->right);
	}
};
