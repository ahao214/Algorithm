using namespace std;
#include<stack>


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//方法一：递归
class Solution {
public:
	int dfs(TreeNode* root, int val) {
		if (root == nullptr) {
			return 0;
		}
		val = (val << 1) | root->val;
		if (root->left == nullptr && root->right == nullptr) {
			return val;
		}
		return dfs(root->left, val) + dfs(root->right, val);
	}

	int sumRootToLeaf(TreeNode* root) {
		return dfs(root, 0);
	}
};


//方法二：迭代
class Solution {
public:
	int sumRootToLeaf(TreeNode* root) {
		stack<TreeNode*> st;
		int val = 0, ret = 0;
		TreeNode* prev = nullptr;
		while (root != nullptr || !st.empty()) {
			while (root != nullptr) {
				val = (val << 1) | root->val;
				st.push(root);
				root = root->left;
			}
			root = st.top();
			if (root->right == nullptr || root->right == prev) {
				if (root->left == nullptr && root->right == nullptr) {
					ret += val;
				}
				val >>= 1;
				st.pop();
				prev = root;
				root = nullptr;
			}
			else {
				root = root->right;
			}
		}
		return ret;
	}
};
