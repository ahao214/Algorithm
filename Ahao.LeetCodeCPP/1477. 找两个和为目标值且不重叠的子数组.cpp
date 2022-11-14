#include<vector>

using namespace std;


/*
1477. 找两个和为目标值且不重叠的子数组

给你一个整数数组 arr 和一个整数值 target 。

请你在 arr 中找 两个互不重叠的子数组 且它们的和都等于 target 。可能会有多种方案，请你返回满足要求的两个子数组长度和的 最小值 。

请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 -1 。
*/
class Solution {
public:
	int minSumOfLengths(vector<int>& arr, int target) {
		int n = arr.size();
		vector<int> f(n, 1e8);

		int res = INT_MAX;
		for (int i = 0, j = 0, sum = 0; i < n; i++)
		{
			sum += arr[i];
			while (sum > target) sum -= arr[j++];
			if (sum == target)
			{
				if (j) res = min(res, i - j + 1 + f[j - 1]);
				f[i] = i - j + 1;
			}
			if (i) f[i] = min(f[i], f[i - 1]);
		}
		if (res > arr.size()) return -1;
		return res;
	}
};