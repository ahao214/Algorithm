#include<vector>
#include <queue>

using namespace std;

/*
107. �������Ĳ������ II

����������ĸ��ڵ� root ��������ڵ�ֵ �Ե����ϵĲ������ �� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q;
		if (root) q.push(root);

		while (q.size())
		{
			vector<int> level;
			int len = q.size();
			while (len--)
			{
				auto t = q.front();
				q.pop();
				level.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(level);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};