#include<vector>

using namespace std;


/*
1038. �Ӷ������������������

����һ������������ root (BST)���뽫����ÿ���ڵ��ֵ�滻�����д��ڻ��ߵ��ڸýڵ�ֵ�����нڵ�ֵ֮�͡�

����һ�£� ���������� ��������Լ��������

�ڵ���������������� С�� �ڵ���Ľڵ㡣
�ڵ���������������� ���� �ڵ���Ľڵ㡣
��������Ҳ�����Ƕ�����������
*/

class Solution {
public:
	int sum = 0;

	TreeNode* bstToGst(TreeNode* root) {
		if (root != nullptr) {
			bstToGst(root->right);
			sum += root->val;
			root->val = sum;
			bstToGst(root->left);
		}
		return root;
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