#include<vector>

using namespace std;


/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有一个重复的整数 ，返回这个重复的数 。

你设计的解决方案必须不修改数组nums且只用常量级O(1)的额外空间。
*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int n = nums.size() - 1;
		int left = 1, right = n;
		while (left < right)
		{
			int mid = left + right >> 1;
			int cnt = 0;
			for (auto x : nums)
			{
				if (x >= 1 && x <= mid)
					cnt++;
			}
			if (cnt > mid - left + 1) right = mid;
			else left = mid + 1;
		}
		return right;
	}
};


class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int left = 1, right = nums.size();
		int res = -1;
		auto comp = [&](int cur)
		{
			int count = 0;
			for (auto n : nums)
			{
				if (n <= cur)
					count++;
			}
			return count;
		};

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (comp(mid) > mid)
			{
				res = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return res;
	}
};
