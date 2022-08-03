#include<vector>

using namespace std;

/*
offer 7 重建二叉树
*/


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int n = pre.size();
		return dfs(pre, vin, 0, n - 1, 0, n - 1);
	}

	TreeNode* dfs(vector<int>& pre, vector<int>& vin, int preLeft, int preRight, int vinLeft, int vinRight)
	{
		if (preLeft > preRight)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(pre[preLeft]);      //根节点
		int k = vinLeft;
		//在中序中找到根节点的位置
		for (k; k <= vinRight; ++k)
		{
			if (vin[k] == pre[preLeft])
				break;
		}
		//左子树长度
		int leftLen = k - vinLeft;
		root->left = dfs(pre, vin, preLeft + 1, preLeft + leftLen, vinLeft, k - 1);
		root->right = dfs(pre, vin, preLeft + 1 + leftLen, preRight, k + 1, vinRight);
		return root;
	}
};



