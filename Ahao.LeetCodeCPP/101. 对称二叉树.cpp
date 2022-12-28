#include<vector>
#include <stack>
#include <queue>

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



/*
101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/
class Solution {
public:
	bool dfs(TreeNode* n1, TreeNode* n2)
	{
		if (!n1 && !n2)
			return true;
		if (!n1 || !n2)
			return false;
		return n1->val == n2->val && dfs(n1->left, n2->right) && dfs(n1->right, n2->left);
	}

	bool isSymmetric(TreeNode* root) {
		if (!root)//为空
		{
			return true;
		}
		return dfs(root->left, root->right);
	}

	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;
		queue<TreeNode*> q;
		q.push(root);
		q.push(root);
		while (!q.empty())
		{
			TreeNode* n1 = q.front();
			q.pop();
			TreeNode* n2 = q.front();
			q.pop();
			if (!n1 && !n2)
				continue;
			if (!n1 || !n2)
				return false;
			if (n1->val != n2->val)
				return false;
			q.push(n1->left);
			q.push(n2->right);
			q.push(n1->right);
			q.push(n2->left);
		}
		return true;
	}
};