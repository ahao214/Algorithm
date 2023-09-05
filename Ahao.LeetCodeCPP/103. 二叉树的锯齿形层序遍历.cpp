#include<vector>
#include<queue>

using namespace std;

/*
103. 二叉树的锯齿形层序遍历

给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q;
		if (root) q.push(root);

		int cnt = 0;
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
			if (++cnt % 2 == 0) reverse(level.begin(), level.end());
			res.push_back(level);
		}
		return res;
	}

};

