#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*
652. 寻找重复的子树
给定一棵二叉树 root，返回所有重复的子树。

对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

如果两棵树具有相同的结构和相同的结点值，则它们是重复的。
*/
class Solution {
public:
	unordered_map<string, int> hash;
	vector<TreeNode*> ans;
	string dfs(TreeNode* u)
	{
		if (!u) return "NULL";
		string left = dfs(u->left);
		string right = dfs(u->right);
		string s = to_string(u->val) + ',' + left + ',' + right;
		if (++hash[s] == 2) ans.push_back(u);
		return s;
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return ans;
	}
};