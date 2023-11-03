#include<vector>

using namespace std;



/*
124. 二叉树中的最大路径和
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。
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
	int ans = INT_MIN;
	int maxPathSum(TreeNode* root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* root)
	{
		if (!root) return 0;
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		ans = max(ans, left + right + root->val);
		return max(0, root->val + max(left, right));
	}
};



class Solution {
	int ans = INT_MIN;
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	int maxPathSum(TreeNode* root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* cur)
	{
		if (!cur) return 0;
		int left = max(0, dfs(cur->left));
		int right = max(0, dfs(cur->right));

		ans = max(ans, cur->val + left + right);
		return cur->val + max(left, right);
	}
};