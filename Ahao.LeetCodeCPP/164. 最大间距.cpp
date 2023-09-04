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
