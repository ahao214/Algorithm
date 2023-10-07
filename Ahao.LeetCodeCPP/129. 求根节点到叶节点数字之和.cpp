#include<vector>

using namespace std;

/*
129. ����ڵ㵽Ҷ�ڵ�����֮��

����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�
ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�

���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��
����Ӹ��ڵ㵽Ҷ�ڵ����ɵ� ��������֮�� ��

Ҷ�ڵ� ��ָû���ӽڵ�Ľڵ㡣
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
	int res = 0;
public:
	int sumNumbers(TreeNode* root) {
		dfs(root, 0);
		return res;
	}

	void dfs(TreeNode* node, int num)
	{
		num = num * 10 + node->val;
		if (!node->left && !node->right)
			res += num;
		if (node->left)
			dfs(node->left, num);
		if (node->right)
			dfs(node->right, num);
	}
};