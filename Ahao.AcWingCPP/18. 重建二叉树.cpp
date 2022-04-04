using namespace std;
#include<vector>

#pragma region 18. 重建二叉树

/*
输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树。

注意:

二叉树中每个节点的值都互不相同；
输入的前序遍历和中序遍历一定合法；
数据范围
树中节点数量范围 [0,100]。
*/

#pragma endregion

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
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