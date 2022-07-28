#include<vector>

using namespace std;



/*
offer 34 二叉树中和为某一值的路径
*/
class Solution {
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> ans;
		if (!root) return ans;
		vector<int> tmp;
		dfs(root, ans, tmp, expectNumber);
		return ans;
	}

	void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int>& tmp, int sum) {
		sum -= root->val;
		tmp.push_back(root->val);

		if (!sum && !root->left && !root->right)
			ans.push_back(tmp);
		if (root->left)
			dfs(root->left, ans, tmp, sum);
		if (root->right)
			dfs(root->right, ans, tmp, sum);

		tmp.pop_back();
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
