#include<vector>

using namespace std;


/*
530. 二叉搜索树的最小绝对差

给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。
*/
class Solution {
public:
	int ans = INT_MAX, last;
	bool isFirst = true;

	int getMinimumDifference(TreeNode* root) {
		dfs(root);
		return ans;
	}

	void dfs(TreeNode* root)
	{
		if (!root) return;
		dfs(root->left);
		if (isFirst)isFirst = false;
		else ans = min(ans, root->val - last);
		last = root->val;
		dfs(root->right);
	}
};


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};