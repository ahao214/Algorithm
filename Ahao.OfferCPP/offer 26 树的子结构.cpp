#include<vector>

using namespace std;


/*
offer 26 树的子结构
*/
class Solution {
	bool HasSubtree(TreeNode* r1, TreeNode* r2) {
		bool res = false;
		if (r1 && r2) {
			res = IsHas(r1, r2);
			if (!res) {
				res = HasSubtree(r1->left, r2) || HasSubtree(r1->right, r2);
			}
		}
		return res;
	}

	bool IsHas(TreeNode* r1, TreeNode* r2) {
		if (r2 == nullptr)	return true;
		if (r1 == nullptr) return false;
		if (r1->val != r2->val) return false;
		return IsHas(r1->left, r2->left) && IsHas(r1->right, r2->right);
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