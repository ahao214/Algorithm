#include<vector>
#include <algorithm>

using namespace std;


/*
1774. 最接近目标价格的甜点成本
你打算做甜点，现在需要购买配料。目前共有 n 种冰激凌基料和 m 种配料可供选购。而制作甜点需要遵循以下几条规则：

必须选择 一种 冰激凌基料。
可以添加 一种或多种 配料，也可以不添加任何配料。
每种类型的配料 最多两份 。
给你以下三个输入：

baseCosts ，一个长度为 n 的整数数组，其中每个 baseCosts[i] 表示第 i 种冰激凌基料的价格。
toppingCosts，一个长度为 m 的整数数组，其中每个 toppingCosts[i] 表示 一份 第 i 种冰激凌配料的价格。
target ，一个整数，表示你制作甜点的目标价格。
你希望自己做的甜点总成本尽可能接近目标价格 target 。

返回最接近 target 的甜点成本。如果有多种方案，返回 成本相对较低 的一种。
*/
class Solution {
public:
	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int res = INT_MAX;
		int n = baseCosts.size(), m = toppingCosts.size();
		for (int i = 0; i < n; i++)
		{
			int s = baseCosts[i];
			for (int j = 0; j < 1 << m * 2; j++)
			{
				int r = s;
				bool flag = false;
				for (int k = 0; k < m; k++)
				{
					int t = j >> k * 2 & 3;
					if (t == 3)
					{
						flag = true;
						break;
					}
					r += toppingCosts[k] * t;
				}
				if (flag) continue;
				if (abs(r - target) < abs(res - target) || abs(r - target) == abs(res - target
				) && r < res)
				{
					res = r;
				}
			}
		}
		return res;
	}
};



class Solution {
public:
	void dfs(const vector<int>& toppingCosts, int p, int curCost, int& res, const int& target) {
		if (abs(res - target) < curCost - target) {
			return;
		}
		else if (abs(res - target) >= abs(curCost - target)) {
			if (abs(res - target) > abs(curCost - target)) {
				res = curCost;
			}
			else {
				res = min(res, curCost);
			}
		}
		if (p == toppingCosts.size()) {
			return;
		}
		dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, res, target);
		dfs(toppingCosts, p + 1, curCost + toppingCosts[p], res, target);
		dfs(toppingCosts, p + 1, curCost, res, target);
	}

	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int res = *min_element(baseCosts.begin(), baseCosts.end());
		for (auto& b : baseCosts) {
			dfs(toppingCosts, 0, b, res, target);
		}
		return res;
	}
};
