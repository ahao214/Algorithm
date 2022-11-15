#include<vector>
#include<string>

using namespace std;



/*
1448. ͳ�ƶ������кýڵ����Ŀ
����һ�ø�Ϊ root �Ķ����������㷵�ض������кýڵ����Ŀ��

���ýڵ㡹X ����Ϊ���Ӹ����ýڵ� X �������Ľڵ��У�û���κνڵ��ֵ���� X ��ֵ��
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
	int goodNodes(TreeNode* root) {
		return dfs(root, INT_MIN);
	}

	int dfs(TreeNode* root, int maxv)
	{
		if (!root) return 0;
		//�жϽڵ��ֵ�Ƿ���ڶ�������ֵ
		int res = maxv <= root->val;
		maxv = max(maxv, root->val);
		return res + dfs(root->left, maxv) + dfs(root->right, maxv);
	}
};
