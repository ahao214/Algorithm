#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
offer 79 判断是不是平衡二叉树
*/
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (!pRoot) return true;
		if (abs(depth(pRoot->left) - depth(pRoot->right)) > 1)
			return false;
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}

	int depth(TreeNode* root)
	{
		if (!root) return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}


	bool IsBalanced_Solution(TreeNode* pRoot) {
		int h = isBalance(pRoot);
		return h != -1;
	}

	int isBalance(TreeNode* root)
	{
		if (!root) return 0;
		int left = isBalance(root->left);
		if (left == -1) return -1;
		int right = isBalance(root->right);
		if (right == -1) return -1;

		int h = (abs(left - right) < 2 ? max(left, right) + 1 : -1);
		return h;
	}

};