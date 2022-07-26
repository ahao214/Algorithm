using namespace std;



/*
offer 54 二叉搜索树的第k个节点
*/

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* ans;
	TreeNode* KthNode(TreeNode* proot, int k) {
		KthNodeCode(proot, k);
		return ans;
	}

	//中序遍历
	void KthNodeCode(TreeNode* root, int& k)
	{
		if (!root) return;
		KthNodeCode(root->left, k);
		if (k == 0) return;
		if (--k == 0)
		{
			ans = root;
			return;
		}
		KthNodeCode(root->right, k);
	}
};
