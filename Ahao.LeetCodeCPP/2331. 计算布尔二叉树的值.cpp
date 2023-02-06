#include<vector>

using namespace std;


/*
2331. ���㲼����������ֵ

����һ�� ���������� �ĸ��������������������

Ҷ�ӽڵ� ҪôֵΪ 0 ҪôֵΪ 1 ������ 0 ��ʾ False ��1 ��ʾ True ��
��Ҷ�ӽڵ� ҪôֵΪ 2 ҪôֵΪ 3 ������ 2 ��ʾ�߼��� OR ��3 ��ʾ�߼��� AND ��
���� һ���ڵ��ֵ��ʽ���£�

����ڵ��Ǹ�Ҷ�ӽڵ㣬��ô�ڵ�� ֵ Ϊ�������� True ���� False ��
���򣬼��� �������ӵĽڵ�ֵ��Ȼ�󽫸ýڵ�����������������ֵ���� ���� ��
���ظ��ڵ� root �Ĳ�������ֵ��

���������� ��ÿ���ڵ��� 0 ������ 2 �����ӵĶ�������

Ҷ�ӽڵ� ��û�к��ӵĽڵ㡣
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
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr) {
            return root->val;
        }
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
        else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};
