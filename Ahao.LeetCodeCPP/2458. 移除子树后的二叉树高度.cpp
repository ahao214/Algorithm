#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;



/*
2458. 移除子树后的二叉树高度

给你一棵 二叉树 的根节点 root ，树中有 n 个节点。每个节点都可以被分配一个从 1 到 n 且互不相同的值。另给你一个长度为 m 的数组 queries 。

你必须在树上执行 m 个 独立 的查询，其中第 i 个查询你需要执行以下操作：

从树中 移除 以 queries[i] 的值作为根节点的子树。题目所用测试用例保证 queries[i] 不 等于根节点的值。
返回一个长度为 m 的数组 answer ，其中 answer[i] 是执行第 i 个查询后树的高度。

注意：

查询之间是独立的，所以在每个查询执行后，树会回到其 初始 状态。
树的高度是从根到树中某个节点的 最长简单路径中的边数 。
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
	int depth[100005];
	int height[100005];
	unordered_map<int, vector<int>>d2h;
public:
	vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
		vector<int> res;
		dfs_height(root, 0);
		for (auto& [d, hs] : d2h) {
			sort(hs.rbegin(), hs.rend());
		}
		for (int node : queries) {
			int d = depth[node];
			int h = height[node];

			if (d2h[d].size() == 1)
				res.push_back(d - 1);
			else if (d2h[d][0] == h)
				res.push_back(d2h[d][1] + d);
			else if (d2h[d][0] != h)
				res.push_back(d2h[d][0] + d);
		}
		return res;
	}

	int dfs_height(TreeNode* node, int d) {
		if (node == nullptr) return -1;
		int h = max(dfs_height(node->left, d + 1), dfs_height(node->right, d + 1)) + 1;
		depth[node->val] = d;
		height[node->val] = h;
		d2h[d].push_back(h);
		return h;
	}
};