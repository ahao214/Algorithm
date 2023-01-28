#include<vector>

using namespace std;



/*
1026. 节点与其祖先之间的最大差值

给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）
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
	int dfs(TreeNode* root, int minv, int maxv)
	{
		if (!root) return -1;
		int val = root->val;
		int res = max(abs(val - minv), abs(val - maxv));
		minv = min(minv, val);
		maxv = max(maxv, val);
		res = max(res, dfs(root->left, minv, maxv));
		res = max(res, dfs(root->right, minv, maxv));
		return res;
	}

	int maxAncestorDiff(TreeNode* root) {
		int val = root->val;
		return max(dfs(root->left, val, val), dfs(root->right, val, val));
	}
};
