#include<vector>
#include<unordered_map>

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
105. ��ǰ��������������й��������
���������������� preorder �� inorder ������ preorder �Ƕ����������������
inorder ��ͬһ����������������빹�����������������ڵ㡣
*/
class Solution {
public:
	unordered_map<int, int> pos;
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; i++)
			pos[inorder[i]] = i;
		return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
	}

	TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
	{
		if (pl > pr) return NULL;
		int val = preorder[pl];
		int k = pos[val];
		int len = k - il;
		auto root = new TreeNode(val);
		root->left = dfs(preorder, inorder, pl + 1, pl + len, il, k - 1);
		root->right = dfs(preorder, inorder, pl + len + 1, pr, k + 1, ir);
		return root;
	}
};
