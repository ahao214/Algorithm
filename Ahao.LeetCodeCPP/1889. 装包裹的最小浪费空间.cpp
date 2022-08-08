#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;


/*
1889. 装包裹的最小浪费空间
给你 n 个包裹，你需要把它们装在箱子里，每个箱子装一个包裹。总共有 m 个供应商提供 不同尺寸 的箱子（每个规格都有无数个箱子）。如果一个包裹的尺寸 小于等于 一个箱子的尺寸，那么这个包裹就可以放入这个箱子之中。

包裹的尺寸用一个整数数组 packages 表示，其中 packages[i] 是第 i 个包裹的尺寸。供应商用二维数组 boxes 表示，其中 boxes[j] 是第 j 个供应商提供的所有箱子尺寸的数组。

你想要选择 一个供应商 并只使用该供应商提供的箱子，使得 总浪费空间最小 。对于每个装了包裹的箱子，我们定义 浪费的 空间等于 箱子的尺寸 - 包裹的尺寸 。总浪费空间 为 所有 箱子中浪费空间的总和。

比方说，如果你想要用尺寸数组为 [4,8] 的箱子装下尺寸为 [2,3,5] 的包裹，你可以将尺寸为 2 和 3 的两个包裹装入两个尺寸为 4 的箱子中，同时把尺寸为 5 的包裹装入尺寸为 8 的箱子中。总浪费空间为 (4-2) + (4-3) + (8-5) = 6 。
请你选择 最优 箱子供应商，使得 总浪费空间最小 。如果 无法 将所有包裹放入箱子中，请你返回 -1 。由于答案可能会 很大 ，请返回它对 109 + 7 取余 的结果。
*/

typedef long long LL;
const LL MOD = 1e9 + 7, INF = 1e18;

class Solution {
public:
	int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
		sort(packages.begin(), packages.end());
		LL sum = accumulate(packages.begin(), packages.end(), 0ll);
		int n = packages.size();
		LL res = INF;
		for (auto& b : boxes)
		{
			sort(b.begin(), b.end());
			if (b.back() < packages.back()) continue;

			LL t = -sum, last = -1;
			for (auto x : b)
			{
				int left = last, right = n - 1;
				while (left < right)
				{
					int mid = left + right + 1 >> 1;
					if (packages[mid] > x)
						right = mid - 1;
					else left = mid;
				}
				if (right == last)continue;
				t += (right - last) * x;
				last = right;
			}
			res = min(res, t);
		}

		if (res == INF) res = -1;
		return res % MOD;
	}

};
