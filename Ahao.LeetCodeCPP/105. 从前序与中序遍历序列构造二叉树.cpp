#include<vector>
#include<unordered_map>

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
105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/
class Solution {
public:
	unordered_map<int, int> pos;
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; i++)
			pos[inorder[i]] = i;
		return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
	}

	TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
	{
		if (pl > pr) return NULL;
		int val = preorder[pl];
		int k = pos[val];
		int len = k - il;
		auto root = new TreeNode(val);
		root->left = dfs(preorder, inorder, pl + 1, pl + len, il, k - 1);
		root->right = dfs(preorder, inorder, pl + len + 1, pr, k + 1, ir);
		return root;
	}
};
