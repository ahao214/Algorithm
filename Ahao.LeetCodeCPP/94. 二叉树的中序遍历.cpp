#include<vector>
#include <stack>

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
94. ���������������
����һ���������ĸ��ڵ� root ���������� ���� ������
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stk;

		auto p = root;
		while (p || stk.size())
		{
			while (p)
			{
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			stk.pop();
			res.push_back(p->val);
			p = p->right;
		}
		return res;
	}
};