#include<vector>
#include <stack>

using namespace std;



/*
144. 二叉树的前序遍历
*/
//时间O(N) 空间O(1)

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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode* cur = root;
		stack<TreeNode*> stk;

		while (cur || !stk.empty())
		{
			while (cur)
			{
				res.push_back(cur->val);
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top();
			stk.pop();
			cur = cur->right;
		}
		return res;

	}
};

