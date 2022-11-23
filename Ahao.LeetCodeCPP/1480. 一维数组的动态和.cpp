#include<vector>

using namespace std;


/*
1480. 一维数组的动态和
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。
*/
class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		vector<int> res(nums.size());
		res[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			res[i] = res[i - 1] + nums[i];
		}
		return res;
	}
};
