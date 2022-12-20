using namespace std;

#include<vector>


/*
53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组
（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int pre = nums[0], ans = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			pre = pre > 0 ? pre + nums[i] : nums[i];
			ans = max(ans, pre);
		}
		return ans;
	}
};




/*
53. 最大子数组和
给你一个整数数组 nums 请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
返回其最大和。

子数组 是数组中的一个连续部分。
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0], sum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			sum = max(0, sum);
			sum += nums[i];
			res = max(res, sum);
		}
		return res;
	}
};