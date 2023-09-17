#include<vector>

using namespace std;



/*
156.上下翻转二叉树
*/
//时间O(N) 空间O(1)



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
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		TreeNode* parent = nullptr, * right = nullptr;
		TreeNode* cur = root;
		while (cur) {
			TreeNode* next = cur->left;
			cur->left = right;
			right = cur->right;
			cur->right = parent;
			parent = cur;
			cur = next;
		}
		return parent;
	}
};
