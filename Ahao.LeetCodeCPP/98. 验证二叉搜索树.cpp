#include<vector>

using namespace std;


/*
98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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
	bool isValidBST(TreeNode* root) {
		if (!root) return true;

		int minV, maxV;
		return dfs(root, minV, maxV);
	}

	bool dfs(TreeNode* root, int& minV, int& maxV)
	{
		minV = maxV = root->val;
		if (root->left)
		{
			int nowMinV, nowMaxV;
			if (!dfs(root->left, nowMinV, nowMaxV)) return false;
			if (nowMaxV >= root->val) return false;
			minV = nowMinV;
		}
		if (root->right)
		{
			int nowMinV, nowMaxV;
			if (!dfs(root->right, nowMinV, nowMaxV)) return false;
			if (nowMinV <= root->val) return false;
			maxV = nowMaxV;
		}
		return true;
	}
};



/*
98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return dfs(root, INT_MIN, INT_MAX);
	}

	bool dfs(TreeNode* root, long long minv, long long maxv)
	{
		if (!root) return true;
		if (root->val < minv || root->val > maxv) return false;

		return dfs(root->left, minv, root->val) && dfs(root->right, root->val, maxv);
	}
};