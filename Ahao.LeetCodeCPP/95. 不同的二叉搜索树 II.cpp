#include<vector>

using namespace std;



/*
95. ��ͬ�Ķ��������� II
����һ������ n ���������ɲ����������� n ���ڵ�����ҽڵ�ֵ�� 1 �� n ������ͬ�Ĳ�ͬ ���������� �����԰� ����˳�� ���ش𰸡�
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
	vector<TreeNode*> generateTrees(int n) {
		if (!n) return vector<TreeNode*>();
		return dfs(1, n);
	}

	vector<TreeNode*> dfs(int left, int right)
	{
		vector<TreeNode*> res;
		if (left > right)
		{
			res.push_back(nullptr);
			return res;
		}
		for (int i = left; i <= right; i++)
		{
			auto leftRoot = dfs(left, i - 1), rightRoot = dfs(i + 1, right);
			for (auto& lt : leftRoot)
			{
				for (auto& rt : rightRoot)
				{
					auto root = new TreeNode(i);
					root->left = lt, root->right = rt;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};