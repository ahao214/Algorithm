#include<vector>
#include <string>

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
257. 二叉树的所有路径
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。
*/
class Solution {
public:
	vector<string> res;
	vector<string> binaryTreePaths(TreeNode* root) {
		string path;
		dfs(root, path);
		return res;
	}

	void dfs(TreeNode* root, string path)
	{
		if (!root) return;
		if (path.size()) path += "->";
		path += to_string(root->val);

		if (!root->left && !root->right)
			res.push_back(path);
		else
		{
			dfs(root->left, path);
			dfs(root->right, path);
		}
	}
};
