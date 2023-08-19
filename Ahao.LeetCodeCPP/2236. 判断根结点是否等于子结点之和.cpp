#include<vector>

using namespace std;

/*
2236. �жϸ�����Ƿ�����ӽ��֮��

����һ�� ������ �ĸ���� root���ö�������ǡ�� 3 �������ɣ�����㡢���ӽ������ӽ�㡣

��������ֵ���������ӽ��ֵ֮�ͣ����� true �����򷵻� false ��
*/



class Solution {
public:
	bool checkTree(TreeNode* root) {
		return root->val == root->left->val + root->right->val;
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