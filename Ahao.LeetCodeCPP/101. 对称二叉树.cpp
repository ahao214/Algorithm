#include<vector>
#include <stack>

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
101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return dfs(root->left, root->right);
	}

	bool dfs(TreeNode* p, TreeNode* q)
	{
		if (!p || !q) return !p && !q;
		return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
	}


	bool isSymmetric(TreeNode* root) {
		//左边：左中右
		//右边：右中左
		if (!root) return true;
		stack<TreeNode*>left, right;
		auto l = root->left, r = root->right;
		while (l || r || left.size() || right.size())
		{
			while (l && r)
			{
				left.push(l), l = l->left;
				right.push(r), r = r->right;
			}

			if (l || r) return false;
			l = left.top(), left.pop();
			r = right.top(), right.pop();
			if (l->val != r->val) return false;

			l = l->right, r = r->left;
		}
		return true;
	}
};