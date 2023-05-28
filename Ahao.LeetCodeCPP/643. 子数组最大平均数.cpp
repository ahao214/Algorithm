#include<vector>
#include <numeric>

using namespace std;


/*
643. 子数组最大平均数 I

给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。

请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。

任何误差小于 10-5 的答案都将被视为正确答案。
*/


class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double sum = accumulate(nums.begin(), nums.begin() + k, 0);
		double res = sum;
		for (int end = k; end < nums.size(); end++)
		{
			sum += nums[end] - nums[end - k];
			res = max(res, sum);
		}
		return res / k;
	}
};


class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double res = -1e5;
		for (int i = 0, j = 0, s = 0; i < nums.size(); i++)
		{
			s += nums[i];
			if (i - j + 1 > k) s -= nums[j++];
			if (i >= k - 1)
			{
				res = max(res, s / (double)k);
			}
		}
		return res;
	}
};

