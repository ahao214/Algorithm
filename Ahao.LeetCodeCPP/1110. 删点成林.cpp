#include<vector>
#include <unordered_set>
#include <functional>

using namespace std;


/*
1110. 删点成林

给出二叉树的根节点 root，树上每个节点都有一个不同的值。

如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。
*/

class Solution {
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
		vector<TreeNode*> roots;

		function<TreeNode* (TreeNode*, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode* {
			if (node == nullptr) {
				return nullptr;
			}
			bool deleted = to_delete_set.count(node->val) ? true : false;
			node->left = dfs(node->left, deleted);
			node->right = dfs(node->right, deleted);
			if (deleted) {
				return nullptr;
			}
			else {
				if (is_root) {
					roots.emplace_back(node);
				}
				return node;
			}
		};

		dfs(root, true);
		return roots;
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