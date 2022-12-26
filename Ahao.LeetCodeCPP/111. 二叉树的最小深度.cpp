#include<vector>

using namespace std;


/*
111. ����������С���
����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
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
	int minDepth(TreeNode* root) {
		//���ڵ�Ϊ��
		if (!root) return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (!left || !right) return left + right + 1;
		return min(left, right) + 1;
	}
};