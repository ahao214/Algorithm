#include<vector>

using namespace std;

/*
1080. 根到叶路径上的不足节点

给你二叉树的根节点 root 和一个整数 limit ，请你同时删除树中所有 不足节点 ，并返回最终二叉树的根节点。

假如通过节点 node 的每种可能的 “根-叶” 路径上值的总和全都小于给定的 limit，则该节点被称之为 不足节点 ，需要被删除。

叶子节点，就是没有子节点的节点。
*/


class Solution {
public:
	bool checkSufficientLeaf(TreeNode* node, int sum, int limit) {
		if (!node) {
			return false;
		}
		if (node->left == nullptr && node->right == nullptr) {
			return node->val + sum >= limit;
		}
		bool haveSufficientLeft = checkSufficientLeaf(node->left, sum + node->val, limit);
		bool haveSufficientRight = checkSufficientLeaf(node->right, sum + node->val, limit);
		if (!haveSufficientLeft) {
			node->left = nullptr;
		}
		if (!haveSufficientRight) {
			node->right = nullptr;
		}
		return haveSufficientLeft || haveSufficientRight;
	}

	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		bool haveSufficient = checkSufficientLeaf(root, 0, limit);
		return haveSufficient ? root : nullptr;
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
