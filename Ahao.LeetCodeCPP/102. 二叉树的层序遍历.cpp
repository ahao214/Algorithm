#include<vector>
#include <string>
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
102. 二叉树的层序遍历

给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
（即逐层地，从左到右访问所有节点）。
*/
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;

		queue<TreeNode*> q;
		q.push(root);

		while (q.size())
		{
			int len = q.size();
			vector<int> level;
			for (int i = 0; i < len; i++)
			{
				auto t = q.front();
				q.pop();
				level.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(level);
		}
		return res;
	}
};



class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q;
		if (root) q.push(root);

		while (q.size())
		{
			vector<int> level;
			int len = q.size();
			while (len--)
			{
				auto t = q.front();
				q.pop();
				level.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(level);
		}
		return res;
	}
};