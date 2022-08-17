#include<vector>

using namespace std;



/*
1302. 层数最深叶子节点的和
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
	int getDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		return 1 + max(getDepth(root->left), getDepth(root->right));
	}

	int helper(TreeNode* root, int depth)
	{
		if (!root)
			return 0;
		if (depth == 1)
			return root->val;
		return helper(root->left, depth - 1) + helper(root->right, depth - 1);
	}

	int deepestLeavesSum(TreeNode* root) {
		int depth = getDepth(root);
		int sum = helper(root, depth);
		return sum;
	}
};


class Solution {
private:
	int maxLevel = -1;
	int sum = 0;

public:
	int deepestLeavesSum(TreeNode* root) {
		dfs(root, 0);
		return sum;
	}

	void dfs(TreeNode* node, int level) {
		if (node == nullptr) {
			return;
		}
		if (level > maxLevel) {
			maxLevel = level;
			sum = node->val;
		}
		else if (level == maxLevel) {
			sum += node->val;
		}
		dfs(node->left, level + 1);
		dfs(node->right, level + 1);
	}
};
