#include<vector>
#include <algorithm>

using namespace std;


/*
327. 区间和的个数
*/
class Solution {
	long res = 0;
	long tmp[100001];
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		vector<long>presum(n + 1);
		for (int i = 0; i < n; i++)
		{
			presum[i + 1] = presum[i] + nums[i];
		}
		helper(presum, 0, n, lower, upper);
		return res;
	}

	void helper(vector<long>& presum, int a, int b, int lower, int upper)
	{
		if (a >= b)
		{
			return;
		}

		int mid = a + (b - a) / 2;
		helper(presum, a, mid, lower, upper);
		helper(presum, mid + 1, b, lower, upper);

		for (int i = a; i <= mid; i++)
		{
			auto x = lower_bound(presum.begin() + mid + 1, presum.begin() + b + 1, presum[i] + lower);
			auto y = upper_bound(presum.begin() + mid + 1, presum.begin() + b + 1, presum[i] + upper);
			res += y - x;
		}

		int i = a, j = mid + 1, p = 0;
		while (i <= mid && j <= b)
		{
			if (presum[i] <= presum[j])
			{
				tmp[p] = presum[i];
				i++;
			}
			else
			{
				tmp[p] = presum[j];
				j++;
			}
			p++;
		}
		while (i <= mid)
		{
			tmp[p] = presum[i];
			p++;
			i++;
		}
		while (j <= b)
		{
			tmp[p] = presum[j];
			p++;
			j++;
		}
		for (int i = 0; i < b - a + 1; i++)
		{
			presum[i + a] = tmp[i];
		}

	}
};