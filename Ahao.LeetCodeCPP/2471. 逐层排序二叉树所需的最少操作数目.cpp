#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;



/*
2471. 逐层排序二叉树所需的最少操作数目

给你一个 值互不相同 的二叉树的根节点 root 。

在一步操作中，你可以选择 同一层 上任意两个节点，交换这两个节点的值。

返回每一层按 严格递增顺序 排序所需的最少操作数目。

节点的 层数 是该节点和根节点之间的路径的边数。
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
	vector<int>level[100005];
	int maxDepth;
public:
	int minimumOperations(TreeNode* root) {
		dfs(root, 0);
		int count = 0;
		for (int t = 0; t <= maxDepth; t++)
		{
			auto& nums = level[t];
			unordered_map<int, int>rank;
			auto sorted = nums;
			sort(sorted.begin(), sorted.end());
			for (int i = 0; i < sorted.size(); i++) {
				rank[sorted[i]] = i;
			}
			for (int i = 0; i < nums.size(); i++) {
				while (rank[nums[i]] != i) {
					swap(nums[i], nums[rank[nums[i]]]);
					count++;
				}
			}
		}
		return count;
	}

	void dfs(TreeNode* node, int depth)
	{
		if (node == nullptr)
			return;
		maxDepth = max(maxDepth, depth);
		level[depth].push_back(node->val);
		dfs(node->left, depth + 1);
		dfs(node->right, depth + 1);
	}
};