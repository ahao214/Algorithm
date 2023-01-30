#include<vector>

using namespace std;


/*
977. 有序数组的平方

给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
*/
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n);
		for (int i = 0, j = n - 1, k = n - 1; i <= j;)
		{
			if (nums[i] * nums[i] > nums[j] * nums[j])
			{
				res[k] = nums[i] * nums[i];
				i++, k--;
			}
			else
			{
				res[k] = nums[j] * nums[j];
				j--, k--;
			}
		}
		return res;
	}
};