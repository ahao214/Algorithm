#include<vector>
#include<string>

using namespace std;



/*
1448. 统计二叉树中好节点的数目
给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
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
	int goodNodes(TreeNode* root) {
		return dfs(root, INT_MIN);
	}

	int dfs(TreeNode* root, int maxv)
	{
		if (!root) return 0;
		//判断节点的值是否大于定义的最大值
		int res = maxv <= root->val;
		maxv = max(maxv, root->val);
		return res + dfs(root->left, maxv) + dfs(root->right, maxv);
	}
};
