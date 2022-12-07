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
543. 二叉树的直径
给定一棵二叉树，你需要计算它的直径长度。
一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
这条路径可能穿过也可能不穿过根结点。
*/
class Solution {
public:
	int ans = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* root)
	{
		if (!root) return 0;
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		ans = max(ans, left + right);
		return max(left + 1, right + 1);
	}
};