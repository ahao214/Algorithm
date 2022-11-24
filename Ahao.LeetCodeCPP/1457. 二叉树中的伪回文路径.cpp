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
1457. 二叉树中的伪回文路径
给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「伪回文」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

请你返回从根到叶子节点的所有路径中 伪回文 路径的数目。
*/
class Solution {
public:
	unordered_map<int, int> cnt;

	int pseudoPalindromicPaths(TreeNode* root) {
		cnt[root->val] ++;
		if (!root->left && !root->right)
		{
			int t = 0;
			for (auto item : cnt)
			{
				if (item.second % 2)
					t++;
			}
			cnt[root->val]--;
			return t <= 1;
		}
		int res = 0;
		if (root->left) res += pseudoPalindromicPaths(root->left);
		if (root->right) res += pseudoPalindromicPaths(root->right);

		cnt[root->val]--;
		return res;
	}
};


