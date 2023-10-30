#include<vector>


using namespace std;


/*
2003. 每棵子树内缺失的最小基因值

有一棵根节点为 0 的 家族树 ，总共包含 n 个节点，节点编号为 0 到 n - 1 。给你一个下标从 0 开始的整数数组 parents ，其中 parents[i] 是节点 i 的父节点。由于节点 0 是 根 ，所以 parents[0] == -1 。

总共有 105 个基因值，每个基因值都用 闭区间 [1, 105] 中的一个整数表示。给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是节点 i 的基因值，且基因值 互不相同 。

请你返回一个数组 ans ，长度为 n ，其中 ans[i] 是以节点 i 为根的子树内 缺失 的 最小 基因值。

节点 x 为根的 子树 包含节点 x 和它所有的 后代 节点。

*/



class Solution {
public:
	vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
		int n = parents.size();
		vector<vector<int>> children(n);
		for (int i = 1; i < n; i++) {
			children[parents[i]].push_back(i);
		}

		vector<int> res(n, 1);
		vector<unordered_set<int>> geneSet(n);
		function<int(int)> dfs = [&](int node) -> int {
			geneSet[node].insert(nums[node]);
			for (auto child : children[node]) {
				res[node] = max(res[node], dfs(child));
				if (geneSet[node].size() < geneSet[child].size()) {
					geneSet[node].swap(geneSet[child]);
				}
				geneSet[node].merge(geneSet[child]);
			}
			while (geneSet[node].count(res[node]) > 0) {
				res[node]++;
			}
			return res[node];
		};
		dfs(0);
		return res;
	}
};



class Solution {
public:
	vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
		int n = parents.size();
		vector<vector<int>> children(n);
		for (int i = 1; i < n; i++) {
			children[parents[i]].push_back(i);
		}

		unordered_set<int> geneSet;
		vector<int> visited(n, 0);
		function<void(int)> dfs = [&](int node) {
			if (visited[node]) {
				return;
			}
			visited[node] = 1;
			geneSet.insert(nums[node]);
			for (auto child : children[node]) {
				dfs(child);
			}
		};

		vector<int> res(n, 1);
		int iNode = 1, node = -1;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 1) {
				node = i;
				break;
			}
		}
		while (node != -1) {
			dfs(node);
			while (geneSet.count(iNode)) {
				iNode++;
			}
			res[node] = iNode;
			node = parents[node];
		}
		return res;
	}
};

