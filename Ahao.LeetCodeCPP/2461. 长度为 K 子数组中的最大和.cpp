#include<vector>
#include<unordered_map>


using namespace std;


/*
2461. 长度为 K 子数组中的最大和

给你一个整数数组 nums 和一个整数 k 。请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：

子数组的长度是 k，且
子数组中的所有元素 各不相同 。
返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。

子数组 是数组中一段连续非空的元素序列。
*/
using LL = long long;
class Solution {
public:
	long long maximumSubarraySum(vector<int>& nums, int k) {
		LL sum = 0;
		LL result = 0;
		unordered_map<int, int> freq;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			freq[nums[i]]++;
			sum += nums[i];
			if (i >= k) {
				freq[nums[i - k]]--;
				if (freq[nums[i - k]] == 0) {
					freq.erase(nums[i - k]);
				}
				sum -= nums[i - k];
			}
			if (i >= k - 1) {
				if (freq.size() == k) {
					result = max(result, sum);
				}
			}
		}
		return result;
	}
};