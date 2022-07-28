#include<vector>

using namespace std;


/*
offer 36 二叉搜索树与双向链表
*/
class Solution {
public:
	TreeNode* ans = nullptr;
	TreeNode* pre = nullptr;

	TreeNode* Convert(TreeNode* pRootOfTree) {
		middleCore(pRootOfTree);
		return ans;
	}

	void middleCore(TreeNode* root) {
		if (!root) return;
		middleCore(root->left);
		if (!ans)
		{
			ans = root;
			pre = root;
		}
		else
		{
			pre->right = root;
			root->left = pre;
			pre = root;
		}
		middleCore(root->right);
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