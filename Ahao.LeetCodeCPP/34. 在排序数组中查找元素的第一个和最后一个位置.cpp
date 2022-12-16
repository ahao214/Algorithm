using namespace std;
#include<vector>


/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。
*/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return { -1,-1 };
		vector<int> ans(2);
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target)
				r = mid;
			else
				l = mid + 1;
		}
		if (nums[l] != target) return { -1,-1 };
		ans[0] = l;

		l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2 + 1;
			if (nums[mid] <= target)
				l = mid;
			else
				r = mid - 1;
		}
		ans[1] = r;
		return ans;
	}
};


