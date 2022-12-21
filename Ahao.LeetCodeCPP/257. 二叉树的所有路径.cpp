#include<vector>
#include <string>

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
257. ������������·��
����һ���������ĸ��ڵ� root ���� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·����

Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
*/
class Solution {
public:
	vector<string> res;
	vector<string> binaryTreePaths(TreeNode* root) {
		string path;
		dfs(root, path);
		return res;
	}

	void dfs(TreeNode* root, string path)
	{
		if (!root) return;
		if (path.size()) path += "->";
		path += to_string(root->val);

		if (!root->left && !root->right)
			res.push_back(path);
		else
		{
			dfs(root->left, path);
			dfs(root->right, path);
		}
	}
};
