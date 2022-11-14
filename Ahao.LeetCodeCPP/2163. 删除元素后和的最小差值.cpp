#include<vector>
#include <queue>

using namespace std;


/*
2163. 删除元素后和的最小差值
给你一个下标从 0 开始的整数数组 nums ，它包含 3 * n 个元素。

你可以从 nums 中删除 恰好 n 个元素，剩下的 2 * n 个元素将会被分成两个 相同大小 的部分。

前面 n 个元素属于第一部分，它们的和记为 sumfirst 。
后面 n 个元素属于第二部分，它们的和记为 sumsecond 。
两部分和的 差值 记为 sumfirst - sumsecond 。

比方说，sumfirst = 3 且 sumsecond = 2 ，它们的差值为 1 。
再比方，sumfirst = 2 且 sumsecond = 3 ，它们的差值为 -1 。
请你返回删除 n 个元素之后，剩下两部分和的 差值的最小值 是多少。
*/
using LL = long long;
class Solution {
public:
	long long minimumDifference(vector<int>& nums) {
		LL ans = 0;
		int N = nums.size();
		int n = N / 3;
		vector<LL> vSmallSum(N);
		vector<LL> vBigSum(N);
		LL sum = 0;
		priority_queue<LL> pSmall;
		for (int i = 0; i < N; i++) {
			pSmall.push(nums[i]);
			sum += nums[i];
			if (pSmall.size() > n) {
				sum -= pSmall.top();
				pSmall.pop();
			}
			vSmallSum[i] = sum;
		}
		sum = 0;
		priority_queue<LL, vector<LL>, greater<LL>> pBig;

		for (int i = N - 1; i >= 0; i--) {
			pBig.push(nums[i]);
			sum += nums[i];
			if (pBig.size() > n) {
				sum -= pBig.top();
				pBig.pop();
			}
			vBigSum[i] = sum;
		}
		ans = vSmallSum[n - 1] - vBigSum[n];
		for (int i = n - 1; i < n * 2; i++) {
			ans = min(ans, vSmallSum[i] - vBigSum[i + 1]);
		}
		return ans;
	}
};
