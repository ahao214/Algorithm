#include<vector>
#include<algorithm>

using namespace std;


/*
1464. 数组中两元素的最大乘积
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int a = nums[0], b = nums[1];
		if (a < b) {
			swap(a, b);
		}
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] > a) {
				b = a;
				a = nums[i];
			}
			else if (nums[i] > b) {
				b = nums[i];
			}
		}
		return (a - 1) * (b - 1);
	}
};


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
				res = max(res, (nums[i] - 1) * (nums[j] - 1));
		}
		return res;
	}
};