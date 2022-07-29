#include<vector>

using namespace std;


/*
offer 27 ¶þ²æÊ÷µÄ¾µÏñ
*/
class Solution {
	TreeNode* Mirror(TreeNode* root) {
		if (!root) return nullptr;
		swap(root->left, root->right);
		Mirror(root->left);
		Mirror(root->right);
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