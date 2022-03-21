using namespace std;
#include<vector>
#include<unordered_set>

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
	void inorder(TreeNode* root, vector<int>& vec)
	{
		if (!root)
			return;
		inorder(root->left, vec);
		vec.push_back(root->val);
		inorder(root->right, vec);
	}

	bool findTarget(TreeNode* root, int k) {
		vector<int> vec;
		inorder(root, vec);
		int left = 0, right = vec.size() - 1;
		while (left < right)
		{
			int sum = vec[left] + vec[right];
			if (sum == k)
			{
				return true;
			}
			if (sum < k)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		return false;
	}

	/// <summary>
	/// 深度优先+哈希表
	/// </summary>
	/// <param name="root"></param>
	/// <param name="k"></param>
	/// <returns></returns>
	unordered_set<int> hashTable;
	bool findTarget1(TreeNode* root, int k) {
		if (root == nullptr) {
			return false;
		}
		if (hashTable.count(k - root->val)) {
			return true;
		}
		hashTable.insert(root->val);
		return findTarget1(root->left, k) || findTarget1(root->right, k);
	}
};