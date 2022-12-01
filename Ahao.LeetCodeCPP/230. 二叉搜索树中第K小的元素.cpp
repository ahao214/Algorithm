#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
230. 二叉搜索树中第K小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，
请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
*/
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		return dfs(root, k);
	}

	int dfs(TreeNode* root, int& k)
	{
		if (!root) return 0;
		int left = dfs(root->left, k);
		if (k <= 0) return left;
		if (--k == 0) return root->val;
		return dfs(root->right, k);
	}
};