#include<queue>
#include<vector>
#include<algorithm>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
offer 77 之字形打印二叉树
*/
class Solution {
public:
	vector<vector<int>> Print(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;
		queue<TreeNode*> q;
		q.push(root);
		bool rev = false;
		while (!q.empty()) {
			rev = !rev;
			vector<int> v;
			int size = q.size();
			while (size) {
				TreeNode* tmp = q.front();
				q.pop();
				v.push_back(tmp->val);
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
				size--;
			}
			if (rev) {
				ans.push_back(v);
			}
			else {
				ans.push_back(vector<int>(v.rbegin(), v.rend()));
			}
		}
		return ans;
	}
};
