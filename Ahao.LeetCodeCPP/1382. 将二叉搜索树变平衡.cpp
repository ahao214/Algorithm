#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


/*
1382. ��������������ƽ��
����һ�ö��������������㷵��һ��ƽ��� �Ķ����������������ɵ���Ӧ����ԭ������������ͬ�Ľڵ�ֵ��

���һ�ö����������У�ÿ���ڵ�����������߶Ȳ���� 1 �����Ǿͳ���ö�����������ƽ��� ��

����ж��ֹ��췽�������㷵������һ�֡�
*/
class Solution {
public:
	vector<TreeNode*> nodes;
	TreeNode* balanceBST(TreeNode* root) {
		dfs(root);
		return build(0, nodes.size() - 1);
	}

	TreeNode* build(int l, int r)
	{
		if (l > r) return NULL;
		int mid = (l + r) / 2;
		nodes[mid]->left = build(l, mid - 1);
		nodes[mid]->right = build(mid + 1, r);
		return nodes[mid];
	}

	void dfs(TreeNode* root)
	{
		if (!root) return;
		dfs(root->left);
		nodes.push_back(root);
		dfs(root->right);
	}
};

