#include<vector>
#include<queue>

using namespace std;


/*
offer 32 不分行从上到下打印二叉树
*/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			TreeNode* tmp = q.front();
			res.push_back(tmp->val);
			q.pop();
			if (tmp->left) {
				q.push(tmp->left);
			}
			if (tmp->right) {
				q.push(tmp->right);
			}
		}
		return res;
	}
};


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
