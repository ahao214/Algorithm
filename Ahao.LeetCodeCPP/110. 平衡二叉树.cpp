#include<vector>
#include <queue>

using namespace std;

/*
110. ƽ�������

����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��

һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
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
	bool ans;
	bool isBalanced(TreeNode* root) {
		ans = true;
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* root)
	{
		if (!root) return 0;
		int lh = dfs(root->left), rh = dfs(root->right);
		if (abs(lh - rh) > 1) ans = false;
		return max(lh, rh) + 1;
	}
};