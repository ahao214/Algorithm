#include<vector>

using namespace std;



/*
971. ��ת��������ƥ���������

����һ�ö������ĸ��ڵ� root �������� n ���ڵ㣬ÿ���ڵ㶼��һ����ͬ�������ڵ��Ҵ��� 1 �� n ֮���ֵ��

�����һ���� n ��ֵ��ɵ��г����� voyage ����ʾ Ԥ�� �Ķ����� ������� �����

ͨ�������ڵ���������������� ��ת �ö������е�����ڵ㡣������ת�ڵ� 1 ��Ч�����£�


�뷭ת ���� �����нڵ㣬ʹ�������� ������� ��Ԥ�ڵı����г� voyage ��ƥ�� ��

������ԣ��򷵻� ��ת�� ���нڵ��ֵ���б�����԰��κ�˳�򷵻ش𰸡�������ܣ��򷵻��б� [-1]��
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
	vector<int> ans;
	bool dfs(TreeNode* root, vector<int>& voyage, int& k)
	{
		if (!root) return true;
		if (root->val != voyage[k]) return false;
		k++;
		if (root->left && root->left->val != voyage[k])
		{
			ans.push_back(root->val);
			return dfs(root->right, voyage, k) && dfs(root->left, voyage, k);
		}
		else
		{
			return dfs(root->left, voyage, k) && dfs(root->right, voyage, k);
		}
	}
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		int k = 0;
		if (dfs(root, voyage, k)) return ans;
		return { -1 };
	}
};

