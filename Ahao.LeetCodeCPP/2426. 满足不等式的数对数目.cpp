#include<vector>

using namespace std;


/*
2426. 满足不等式的数对数目

给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两个数组的大小都为 n ，同时给你一个整数 diff ，统计满足以下条件的 数对 (i, j) ：

0 <= i < j <= n - 1 且
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
请你返回满足条件的 数对数目 。
*/
using LL = long long;
class Solution {
	LL res = 0;
	LL diff;
public:
	long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
		int n = nums1.size();
		this->diff = diff;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			arr[i] = nums1[i] - nums2[i];
		}
		helper(arr, 0, arr.size() - 1);
		return res;
	}

	void helper(vector<int>& arr, int a, int b)
	{
		if (a == b)
			return;
		int mid = a + (b - a) / 2;
		helper(arr, a, mid);
		helper(arr, mid + 1, b);

		int i = a;
		for (int j = mid + 1; j <= b; j++)
		{
			while (i <= mid && arr[i] <= arr[j] + diff)
				i++;
			res += i - a;
		}

		inplace_merge(arr.begin() + a, arr.begin() + mid + 1, arr.begin() + b + 1);

	}
};

