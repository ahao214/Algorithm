#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
offer 78 把二叉树打印成多行
*/
class Solution {
public:
	vector<vector<int>> Print(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
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
			ans.push_back(v);
		}
		return ans;
	}
}