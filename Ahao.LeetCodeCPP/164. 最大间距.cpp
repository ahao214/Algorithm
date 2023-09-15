#include<vector>


using namespace std;


/*
164. 最大间距

给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。

您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
*/

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		struct Range {
			int min, max;
			bool used;
			Range() :min(INT_MAX), max(INT_MIN), used(false) {}
		};
		int n = nums.size();
		int Min = INT_MAX, Max = INT_MIN;
		for (auto x : nums)
		{
			Min = min(Min, x);
			Max = max(Max, x);
		}
		if (n < 2 || Min == Max) return 0;
		vector<Range> r(n);
		int len = (Max - Min + n - 2) / (n - 1);
		for (auto x : nums)
		{
			if (x == Min) continue;
			int k = (x - Min - 1) / len;
			r[k].used = true;
			r[k].min = min(r[k].min, x);
			r[k].max = max(r[k].max, x);
		}
		int res = 0;
		for (int i = 0, last = Min; i < n - 1; i++)
		{
			if (r[i].used)
			{
				res = max(res, r[i].min - last);
				last = r[i].max;
			}
		}
		return res;
	}
};





class Solution {
	struct bucket {
		int minVal, maxVal;
		bool used;
		bucket() : minVal(INT_MAX), maxVal(INT_MIN), used(false) {}
	};
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;

		int minVal = INT_MAX, maxVal = INT_MIN;
		for (auto num : nums)
		{
			minVal = min(minVal, num);
			maxVal = max(maxVal, num);
		}

		int d = max(1, (maxVal - minVal) / (n - 1));
		int size = (maxVal - minVal) / d + 1;

		vector<bucket> buckets(size);
		for (int i = 0; i < n; i++)
		{
			int idx = (nums[i] - minVal) / d;
			buckets[idx].used = true;
			buckets[idx].minVal = min(nums[i], buckets[idx].minVal);
			buckets[idx].maxVal = max(nums[i], buckets[idx].maxVal);
		}

		int res = 0;
		for (int i = 0, last = minVal; i < size; i++)
		{
			if (buckets[i].used)
			{
				res = max(res, buckets[i].minVal - last);
				last = buckets[i].maxVal;
			}
		}
		return res;
	}
};