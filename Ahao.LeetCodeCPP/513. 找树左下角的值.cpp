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

//深度优先搜索
class Solution {
public:
	void dfs(TreeNode* root, int height, int& curVal, int& curHeight) {
		if (root == nullptr) {
			return;
		}
		height++;
		dfs(root->left, height, curVal, curHeight);
		dfs(root->right, height, curVal, curHeight);
		if (height > curHeight) {
			curHeight = height;
			curVal = root->val;
		}
	}

	int findBottomLeftValue(TreeNode* root) {
		int curVal, curHeight = 0;
		dfs(root, 0, curVal, curHeight);
		return curVal;
	}
};




//广度优先搜索
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		int ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			if (p->right) {
				q.push(p->right);
			}
			if (p->left) {
				q.push(p->left);
			}
			ret = p->val;
		}
		return ret;
	}
};
