#include<vector>
#include <unordered_map>

using namespace std;

/*
106. 从中序与后序遍历序列构造二叉树

给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
*/


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};




class Solution {
public:
	unordered_map<int, int> pos;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		for (int i = 0; i < inorder.size(); i++)
			pos[inorder[i]] = i;
		return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}

	TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr)
	{
		if (il > ir) return NULL;
		auto root = new TreeNode(postorder[pr]);
		int k = pos[root->val];
		root->left = build(inorder, postorder, il, k - 1, pl, pl + k - 1 - il);
		root->right = build(inorder, postorder, k + 1, ir, pl + k - il, pr - 1);
		return root;
	}

};