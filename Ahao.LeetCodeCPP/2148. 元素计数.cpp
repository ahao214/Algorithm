#include<vector>
#include<algorithm>

using namespace std;


/*
2148. 元素计数
给你一个整数数组 nums ，统计并返回在 nums 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。
*/
class Solution {
public:
	//判断大于最小值和小于最大值的数字的个数
	int countElements(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (auto x : nums)
			if (x > nums[0] && x < nums.back())
				res++;
		return res;
	}

};