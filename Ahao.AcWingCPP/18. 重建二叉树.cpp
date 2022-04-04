using namespace std;
#include<vector>

#pragma region 18. �ؽ�������

/*
����һ�ö�����ǰ���������������Ľ�������ؽ��ö�������

ע��:

��������ÿ���ڵ��ֵ��������ͬ��
�����ǰ��������������һ���Ϸ���
���ݷ�Χ
���нڵ�������Χ [0,100]��
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
        TreeNode* root = new TreeNode(pre[preLeft]);      //���ڵ�
        int k = vinLeft;
        //���������ҵ����ڵ��λ��
        for (k; k <= vinRight; ++k)
        {
            if (vin[k] == pre[preLeft])
                break;
        }
        //����������
        int leftLen = k - vinLeft;
        root->left = dfs(pre, vin, preLeft + 1, preLeft + leftLen, vinLeft, k - 1);
        root->right = dfs(pre, vin, preLeft + 1 + leftLen, preRight, k + 1, vinRight);
        return root;
    }
};