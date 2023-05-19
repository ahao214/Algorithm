#include<vector>

using namespace std;

/*
1373. 二叉搜索子树的最大键值和

给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。

二叉搜索树的定义如下：

任意节点的左子树中的键值都 小于 此节点的键值。
任意节点的右子树中的键值都 大于 此节点的键值。
任意节点的左子树和右子树都是二叉搜索树。

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
	static constexpr int inf = 0x3f3f3f3f;
	int res;
	struct SubTree {
		bool isBST;
		int minValue;
		int maxValue;
		int sumValue;
		SubTree(bool isBST, int minValue, int maxValue, int sumValue) : isBST(isBST), minValue(minValue), maxValue(maxValue), sumValue(sumValue) {}
	};

	SubTree dfs(TreeNode* root) {
		if (root == nullptr) {
			return SubTree(true, inf, -inf, 0);
		}
		auto left = dfs(root->left);
		auto right = dfs(root->right);

		if (left.isBST && right.isBST &&
			root->val > left.maxValue &&
			root->val < right.minValue) {
			int sum = root->val + left.sumValue + right.sumValue;
			res = max(res, sum);
			return SubTree(true, min(left.minValue, root->val),
				max(root->val, right.maxValue), sum);
		}
		else {
			return SubTree(false, 0, 0, 0);
		}
	}

	int maxSumBST(TreeNode* root) {
		res = 0;
		dfs(root);
		return res;
	}
};
