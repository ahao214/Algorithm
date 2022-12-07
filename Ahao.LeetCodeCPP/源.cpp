#include<vector>
#include <string>

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
236. �������������������
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q��
����������ȱ�ʾΪһ���ڵ� x��
���� x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
*/
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == q || root == p) return root;
		auto left = lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);

		if (!left) return right;
		if (!right) return left;
		return root;
	}
};