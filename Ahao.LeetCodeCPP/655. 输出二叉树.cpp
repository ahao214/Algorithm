#include<vector>
#include <string>

using namespace std;


/*
655. 输出二叉树

给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：

树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
矩阵的列数 n 应该等于 2height+1 - 1 。
根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
继续这一过程，直到树中的所有节点都妥善放置。
任意空单元格都应该包含空字符串 "" 。
返回构造得到的矩阵 res 。
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
	vector<vector<string>> ans;
	vector<int> dfs(TreeNode* root)
	{
		if (!root) return { 0,0 };
		auto left = dfs(root->left), right = dfs(root->right);
		return { max(left[0],right[0]) + 1,max(left[1],right[1]) * 2 + 1 };
	}

	void print(TreeNode* root, int height, int left, int right)
	{
		if (!root) return;
		int mid = (left + right) / 2;
		ans[height][mid] = to_string(root->val);
		print(root->left, height + 1, left, mid - 1);
		print(root->right, height + 1, mid + 1, right);
	}

	vector<vector<string>> printTree(TreeNode* root) {
		auto t = dfs(root);
		int height = t[0], width = t[1];
		ans = vector<vector<string>>(height, vector<string>(width));
		print(root, 0, 0, width - 1);
		return ans;
	}
};