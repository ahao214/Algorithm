#include<vector>

using namespace std;

/*
654. ×î´ó¶þ²æÊ÷
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
	int n, k;
	vector<vector<int>> f;
	vector<int> ns;
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		ns = nums;
		n = ns.size();
		k = log(n) / log(2);
		f = vector<vector<int>>(n, vector<int>(k + 1));
		for (int j = 0; j <= k; j++)
		{
			for (int i = 0; i + (1 << j) - 1 < n; i++)
			{
				if (!j) f[i][j] = i;
				else
				{
					int left = f[i][j - 1], right = f[i + (1 << j - 1)][j - 1];
					if (ns[left] > ns[right]) f[i][j] = left;
					else f[i][j] = right;
				}
			}
		}
		return build(0, n - 1);
	}

	int query(int left, int right)
	{
		int len = right - left + 1;
		int s = log(len) / log(2);
		int a = f[left][s], b = f[right - (1 << s) + 1][s];
		if (ns[a] > ns[b]) return a;
		return b;
	}

	TreeNode* build(int left, int right)
	{
		if (left > right) return NULL;
		int k = query(left, right);
		auto root = new TreeNode(ns[k]);
		root->left = build(left, k - 1);
		root->right = build(k + 1, right);
		return root;
	}
};
