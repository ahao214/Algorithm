#include<vector>

using namespace std;


/*
872. Ҷ�����Ƶ���

�뿼��һ�ö����������е�Ҷ�ӣ���ЩҶ�ӵ�ֵ�������ҵ�˳�������γ�һ�� Ҷֵ���� ��

�ٸ����ӣ�����ͼ��ʾ������һ��Ҷֵ����Ϊ (6, 7, 4, 9, 8) ������

��������ö�������Ҷֵ��������ͬ����ô���Ǿ���Ϊ������ Ҷ���� �ġ�

������������������ֱ�Ϊ root1 �� root2 ������Ҷ���Ƶģ��򷵻� true�����򷵻� false ��
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
	void dfs(TreeNode* root, vector<int>& a)
	{
		if (!root) return;
		if (!root->left && !root->right)
			a.push_back(root->val);
		dfs(root->left, a);
		dfs(root->right, a);
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> a, b;
		dfs(root1, a);
		dfs(root2, b);
		return a == b;
	}
};
