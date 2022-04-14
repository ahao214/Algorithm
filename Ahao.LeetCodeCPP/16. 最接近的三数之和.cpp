using namespace std;
#include<vector>
#include <algorithm>

class Solution {
	/*
	16. 最接近的三数之和
	给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

	返回这三个数的和。

	假定每组输入只存在恰好一个解。
	*/
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int res = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			int l = i + 1, r = nums.size() - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == target) return sum;
				if (abs(sum - target) < abs(res - target))
					res = sum;
				if (sum < target)
					l++;
				else
					r--;
			}
		}
		return res;
	}
};
