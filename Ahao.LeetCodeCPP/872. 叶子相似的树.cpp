#include<vector>

using namespace std;


/*
872. 叶子相似的树

请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。

举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
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
	void dfs(TreeNode* root, vector<int>& a)
	{
		if (!root) return;
		if (!root->left && !root->right)
			a.push_back(root->val);
		dfs(root->left, a);
		dfs(root->right, a);
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> a, b;
		dfs(root1, a);
		dfs(root2, b);
		return a == b;
	}
};
