#include<vector>

using namespace std;



/*
124. �������е����·����
·�� ������Ϊһ������������ڵ�������ظ��ڵ�-�ӽڵ����ӣ��ﵽ����ڵ�����С�ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣

·���� ��·���и��ڵ�ֵ���ܺ͡�

����һ���������ĸ��ڵ� root �������� ���·���� ��
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
	int ans = INT_MIN;
	int maxPathSum(TreeNode* root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* root)
	{
		if (!root) return 0;
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		ans = max(ans, left + right + root->val);
		return max(0, root->val + max(left, right));
	}
};
