#include<vector>

using namespace std;



/*
971. 翻转二叉树以匹配先序遍历

给你一棵二叉树的根节点 root ，树中有 n 个节点，每个节点都有一个不同于其他节点且处于 1 到 n 之间的值。

另给你一个由 n 个值组成的行程序列 voyage ，表示 预期 的二叉树 先序遍历 结果。

通过交换节点的左右子树，可以 翻转 该二叉树中的任意节点。例，翻转节点 1 的效果如下：


请翻转 最少 的树中节点，使二叉树的 先序遍历 与预期的遍历行程 voyage 相匹配 。

如果可以，则返回 翻转的 所有节点的值的列表。你可以按任何顺序返回答案。如果不能，则返回列表 [-1]。
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
	vector<int> ans;
	bool dfs(TreeNode* root, vector<int>& voyage, int& k)
	{
		if (!root) return true;
		if (root->val != voyage[k]) return false;
		k++;
		if (root->left && root->left->val != voyage[k])
		{
			ans.push_back(root->val);
			return dfs(root->right, voyage, k) && dfs(root->left, voyage, k);
		}
		else
		{
			return dfs(root->left, voyage, k) && dfs(root->right, voyage, k);
		}
	}
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		int k = 0;
		if (dfs(root, voyage, k)) return ans;
		return { -1 };
	}
};

