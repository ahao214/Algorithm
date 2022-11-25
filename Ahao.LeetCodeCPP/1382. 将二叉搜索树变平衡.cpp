#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


/*
1382. 将二叉搜索树变平衡
给你一棵二叉搜索树，请你返回一棵平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。

如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是平衡的 。

如果有多种构造方法，请你返回任意一种。
*/
class Solution {
public:
	vector<TreeNode*> nodes;
	TreeNode* balanceBST(TreeNode* root) {
		dfs(root);
		return build(0, nodes.size() - 1);
	}

	TreeNode* build(int l, int r)
	{
		if (l > r) return NULL;
		int mid = (l + r) / 2;
		nodes[mid]->left = build(l, mid - 1);
		nodes[mid]->right = build(mid + 1, r);
		return nodes[mid];
	}

	void dfs(TreeNode* root)
	{
		if (!root) return;
		dfs(root->left);
		nodes.push_back(root);
		dfs(root->right);
	}
};

