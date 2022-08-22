#include<vector>

using namespace std;


/*
1856. 子数组最小乘积的最大值
一个数组的 最小乘积 定义为这个数组中 最小值 乘以 数组的 和 。

比方说，数组 [3,2,5] （最小值是 2）的最小乘积为 2 * (3+2+5) = 2 * 10 = 20 。
给你一个正整数数组 nums ，请你返回 nums 任意 非空子数组 的最小乘积 的 最大值 。由于答案可能很大，请你返回答案对  109 + 7 取余 的结果。

请注意，最小乘积的最大值考虑的是取余操作 之前 的结果。题目保证最小乘积的最大值在 不取余 的情况下可以用 64 位有符号整数 保存。

子数组 定义为一个数组的 连续 部分。
*/

typedef long long LL;

const int N = 100010;

class Solution {
public:
	int h[N], left[N], right[N], q[N];

	LL s[N];
	int maxSumMinProduct(vector<int>& nums) {
		int n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			h[i] = nums[i - 1];
			s[i] = s[i - 1] + h[i];
		}
		h[0] = h[n + 1] = 0;
		int tt = 0;
		q[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			while (h[i] <= h[q[tt]]) tt--;
			left[i] = q[tt];
			q[++tt] = i;
		}

		tt = 0;
		q[0] = n + 1;
		for (int i = n; i; i--)
		{
			while (h[i] <= h[q[tt]]) tt--;
			right[i] = q[tt];
			q[++tt] = i;
		}

		LL res = 0;
		for (int i = 1; i <= n; i++)
			res = max(res, h[i] * (s[right[i] - 1] - s[left[i]]));
		return res % 1000000007;
	}
};
