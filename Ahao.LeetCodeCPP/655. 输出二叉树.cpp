#include<vector>
#include <string>

using namespace std;


/*
655. ���������

����һ�ö������ĸ��ڵ� root �����㹹��һ���±�� 0 ��ʼ����СΪ m x n ���ַ������� res �����Ա�ʾ���� ��ʽ������ ������˸�ʽ�����־�����Ҫ��ѭ���¹���

���� �߶� Ϊ height ����������� m Ӧ�õ��� height + 1 ��
��������� n Ӧ�õ��� 2height+1 - 1 ��
���ڵ� ��Ҫ������ ���� �� ���м� ����Ӧλ��Ϊ res[0][(n-1)/2] ��
���ڷ����ھ����е�ÿ���ڵ㣬���Ӧλ��Ϊ res[r][c] ���������ӽڵ������ res[r+1][c-2height-r-1] �����ӽڵ������ res[r+1][c+2height-r-1] ��
������һ���̣�ֱ�����е����нڵ㶼���Ʒ��á�
����յ�Ԫ��Ӧ�ð������ַ��� "" ��
���ع���õ��ľ��� res ��
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
	vector<vector<string>> ans;
	vector<int> dfs(TreeNode* root)
	{
		if (!root) return { 0,0 };
		auto left = dfs(root->left), right = dfs(root->right);
		return { max(left[0],right[0]) + 1,max(left[1],right[1]) * 2 + 1 };
	}

	void print(TreeNode* root, int height, int left, int right)
	{
		if (!root) return;
		int mid = (left + right) / 2;
		ans[height][mid] = to_string(root->val);
		print(root->left, height + 1, left, mid - 1);
		print(root->right, height + 1, mid + 1, right);
	}

	vector<vector<string>> printTree(TreeNode* root) {
		auto t = dfs(root);
		int height = t[0], width = t[1];
		ans = vector<vector<string>>(height, vector<string>(width));
		print(root, 0, 0, width - 1);
		return ans;
	}
};