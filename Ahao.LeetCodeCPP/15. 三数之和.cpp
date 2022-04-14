using namespace std;
#include<vector>
#include <unordered_map>
#include <queue>


class Solution {
	/*
	15. 三数之和
	给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

	注意：答案中不可以包含重复的三元组。
	*/
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			//去重
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1, r = nums.size() - 1;
			int target = 0 - nums[i];
			while (l < r) {
				if (nums[l] + nums[r] == target) {
					res.push_back({ nums[i],nums[l],nums[r] });
					//去重
					while (l < r && nums[l] == nums[l + 1]) l++;
					while (l < r && nums[r] == nums[r - 1]) r--;
					l++, r--;
				}
				else if (nums[l] + nums[r] < target) {
					l++;
				}
				else {
					r--;
				}
			}
		}
		return res;
	}
};

