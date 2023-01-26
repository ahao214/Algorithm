#include<vector>
#include<unordered_map>


using namespace std;


/*
1027. 最长等差数列

给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。

回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ... < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1) 的值都相同，那么序列 seq 是等差的。
*/
class Solution {
public:
	int longestArithSeqLength(vector<int>& nums) {
		int n = nums.size();
		vector<unordered_map<int, int>> f(n);

		int res = 2;
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < i; k++)
			{
				int j = nums[k] - nums[i];
				f[i][j] = max(f[i][j], 2);
				if (f[k].count(j))
				{
					f[i][j] = max(f[i][j], f[k][j] + 1);
					res = max(res, f[i][j]);
				}
			}
		}
		return res;
	}
};