#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};




/*
543. ��������ֱ��
����һ�ö�����������Ҫ��������ֱ�����ȡ�
һ�ö�������ֱ�������������������·�������е����ֵ��
����·�����ܴ���Ҳ���ܲ���������㡣
*/
class Solution {
public:
	int ans = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* root)
	{
		if (!root) return 0;
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		ans = max(ans, left + right);
		return max(left + 1, right + 1);
	}
};