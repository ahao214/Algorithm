#include<vector>

using namespace std;



/*
404. ��Ҷ��֮��
*/
class Solution {
public:
	int res = 0;
	int sumOfLeftLeaves(TreeNode* root) {
		dfs(root);
		return res;
	}

	void dfs(TreeNode* root)
	{
		if (!root) return;
		if (root->left)
		{
			if (!root->left->left && !root->left->right)
				res += root->left->val;
		}
		dfs(root->left);
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