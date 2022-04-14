using namespace std;
#include<vector>
#include<algorithm>


class Solution {
	/*
	18. 四数之和
	给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

	0 <= a, b, c, d < n
	a、b、c 和 d 互不相同
	nums[a] + nums[b] + nums[c] + nums[d] == target
	你可以按 任意顺序 返回答案 。
	*/
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int l = j + 1, r = nums.size() - 1;
				int sum = target - nums[i] - nums[j];
				while (l < r) {
					if (nums[l] + nums[r] == sum) {
						ans.push_back({ nums[i],nums[j],nums[l],nums[r] });
						while (l < r && nums[l] == nums[l + 1]) l++;
						while (l < r && nums[r] == nums[r - 1]) r--;
						l++, r--;
					}
					else if (nums[l] + nums[r] < sum) {
						l++;
					}
					else {
						r--;
					}
				}
			}
		}
		return ans;
	}
};

