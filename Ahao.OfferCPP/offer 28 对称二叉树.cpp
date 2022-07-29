#include<vector>

using namespace std;


/*
offer 28 对称二叉树
*/
class Solution {
public:
	bool isSymmetrical(TreeNode* root) {
		//空树为真
		if (!root) return true;

		return dfs(root->left, root->right) :
	}

	bool dfs(TreeNode* r1, TreeNode* r2) {
		if (!r1 && !r2) return true;
		if (!r1 || !r2) return false;
		if (r1->val != r2->val) return false;

		return dfs(r1->left, r2->right) && dfs(r1->right, r1->left);
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