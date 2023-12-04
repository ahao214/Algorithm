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


class Solution {
public:
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;

        while (node != nullptr) {
            if (node->right == nullptr) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            else {
                TreeNode* succ = getSuccessor(node);
                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                }
                else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
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