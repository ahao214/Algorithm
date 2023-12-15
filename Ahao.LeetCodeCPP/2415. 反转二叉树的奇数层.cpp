#include<vector>
#include <queue>

using namespace std;

/*
2415. ��ת��������������

����һ�� ���� �������ĸ��ڵ� root �����㷴ת�������ÿ�� ���� ��Ľڵ�ֵ��

���磬����� 3 ��Ľڵ�ֵ�� [2,1,3,4,7,11,29,18] ����ô��ת����Ӧ�ñ�� [18,29,11,7,4,3,1,2] ��
��ת�󣬷������ĸ��ڵ㡣

���� �����������㣺�����������и��ڵ㶼�������ӽڵ㣬������Ҷ�ӽڵ㶼��ͬһ�㡣

�ڵ�� ���� ���ڸýڵ㵽���ڵ�֮��ı�����
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.emplace(root);
        bool isOdd = false;
        while (!qu.empty()) {
            int sz = qu.size();
            vector<TreeNode*> arr;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                if (isOdd) {
                    arr.emplace_back(node);
                }
                if (node->left) {
                    qu.emplace(node->left);
                    qu.emplace(node->right);
                }
            }
            if (isOdd) {
                for (int l = 0, r = sz - 1; l < r; l++, r--) {
                    swap(arr[l]->val, arr[r]->val);
                }
            }
            isOdd ^= true;
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }

    void dfs(TreeNode* root1, TreeNode* root2, bool isOdd) {
        if (root1 == nullptr) {
            return;
        }
        if (isOdd) {
            swap(root1->val, root2->val);
        }
        dfs(root1->left, root2->right, !isOdd);
        dfs(root1->right, root2->left, !isOdd);
    }
};
