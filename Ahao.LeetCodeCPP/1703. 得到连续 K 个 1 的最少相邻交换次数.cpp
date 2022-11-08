#include<vector>

using namespace std;


/*
1703. 得到连续 K 个 1 的最少相邻交换次数
给你一个整数数组 nums 和一个整数 k 。 nums 仅包含 0 和 1 。每一次移动，你可以选择 相邻 两个数字并将它们交换。

请你返回使 nums 中包含 k 个 连续 1 的 最少 交换次数。
*/
class Solution {
public:
	int minMoves(vector<int>& nums, int k) {
		vector<int> a;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i])
				a.push_back(i - a.size());
		}
		int n = a.size();
		typedef long long LL;
		vector<LL> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
		LL res = 1e8;
		for (int i = k; i <= n; i++)
		{
			int le = i - k + 1, ri = i;
			int mid = (le + ri) / 2;
			LL x = a[mid - 1];
			LL left = x * (mid - le) - (s[mid - 1] - s[le - 1]);
			LL right = (s[ri] - s[mid]) - x * (ri - mid);
			res = min(res, left + right);
		}
		return res;
	}
};