#include<vector>

using namespace std;


/*
1775. 通过最少操作次数使数组的和相等
给你两个长度可能不等的整数数组 nums1 和 nums2 。两个数组中的所有值都在 1 到 6 之间（包含 1 和 6）。

每次操作中，你可以选择 任意 数组中的任意一个整数，将它变成 1 到 6 之间 任意 的值（包含 1 和 6）。

请你返回使 nums1 中所有数的和与 nums2 中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 -1 。
*/
class Solution {
public:
	int work(vector<int>& h, int s)
	{
		int sum = 0;
		for (int i = 1; i <= 6; i++)
			sum += i * h[i];

		if (sum > s)
		{
			int x = sum - s, res = 0;
			for (int i = 6; i > 1; i--)
			{
				int t = i - 1;
				if (h[i] * t >= x) return res + (x + t - 1) / t;
				res += h[i];
				x -= h[i] * t;
			}
			return res;
		}
		else {
			int x = s - sum, res = 0;
			for (int i = 1; i < 6; i++)
			{
				int t = 6 - i;
				if (h[i] * t >= x) return res + (x + t - 1) / t;
				res += h[i];
				x -= h[i] * t;
			}
			return res;
		}
	}

	int minOperations(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		if (n > m) return minOperations(nums2, nums1);

		if (m > n * 6) return -1;

		vector<int> h1(7), h2(7);
		for (auto x : nums1) h1[x]++;
		for (auto x : nums2) h2[x]++;
		int res = 1e9;
		for (int i = m; i <= 6 * n; i++)
			res = min(res, work(h1, i) + work(h2, i));
		return res;
	}

};
