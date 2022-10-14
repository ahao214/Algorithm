#include<vector>
#include<unordered_map>


using namespace std;


/*
1743. 从相邻元素对还原数组
存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。

给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。

题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。

返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
*/
class Solution {
public:
	/*
	二维数组中，出现次数是1次的，是原数组的首位值
	*/

	unordered_map<int, vector<int>> g;
	vector<int> path;

	//u是当前节点 father是父节点
	void dfs(int u, int father)
	{
		path.push_back(u);
		for (int x : g[u])
		{
			if (x != father)
				dfs(x, u);
		}
	}

	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, int> cnt;
		//计算每个数出现的次数
		for (auto& e : adjacentPairs)
		{
			int a = e[0], b = e[1];
			g[a].push_back(b), g[b].push_back(a);
			cnt[a]++, cnt[b]++;
		}

		int root = 0;
		for (auto [k, v] : cnt)
		{
			if (v == 1)
			{
				root = k;
				break;
			}
		}
		dfs(root, -1);
		return path;
	}
};
