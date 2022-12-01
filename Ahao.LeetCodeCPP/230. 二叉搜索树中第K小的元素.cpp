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
230. �����������е�KС��Ԫ��
����һ�������������ĸ��ڵ� root ����һ������ k ��
�������һ���㷨�������е� k ����СԪ�أ��� 1 ��ʼ��������
*/
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		return dfs(root, k);
	}

	int dfs(TreeNode* root, int& k)
	{
		if (!root) return 0;
		int left = dfs(root->left, k);
		if (k <= 0) return left;
		if (--k == 0) return root->val;
		return dfs(root->right, k);
	}
};