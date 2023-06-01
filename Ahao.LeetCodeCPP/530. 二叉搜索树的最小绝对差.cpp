#include<vector>

using namespace std;


/*
530. ��������������С���Բ�

����һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ��

��ֵ��һ������������ֵ������ֵ֮��ľ���ֵ��
*/
class Solution {
public:
	int ans = INT_MAX, last;
	bool isFirst = true;

	int getMinimumDifference(TreeNode* root) {
		dfs(root);
		return ans;
	}

	void dfs(TreeNode* root)
	{
		if (!root) return;
		dfs(root->left);
		if (isFirst)isFirst = false;
		else ans = min(ans, root->val - last);
		last = root->val;
		dfs(root->right);
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