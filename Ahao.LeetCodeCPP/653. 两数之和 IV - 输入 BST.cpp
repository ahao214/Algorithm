using namespace std;
#include<vector>
#include<unordered_set>
#include <queue>

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

	/// <summary>
	/// 广度优先+哈希表
	/// </summary>
	/// <param name="root"></param>
	/// <param name="k"></param>
	/// <returns></returns>
	bool findTarget2(TreeNode* root, int k) {
		unordered_set<int> hashTable;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			TreeNode* node = que.front();
			que.pop();
			if (hashTable.count(k - node->val)) {
				return true;
			}
			hashTable.insert(node->val);
			if (node->left != nullptr) {
				que.push(node->left);
			}
			if (node->right != nullptr) {
				que.push(node->right);
			}
		}
		return false;
	}
};



/*
653. 两数之和 IV - 输入 BST
给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
*/
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
};




/*
653. 两数之和 IV - 输入 BST
*/
class Solution {
public:
	unordered_set<int> hash;
	bool findTarget(TreeNode* root, int k) {
		return dfs(root, k);
	}

	bool dfs(TreeNode* root, int k)
	{
		if (!root) return false;
		if (dfs(root->left, k)) return true;
		int x = root->val;
		if (hash.count(k - x)) return true;
		hash.insert(x);
		return dfs(root->right, k);
	}
};
