#include<vector>
#include <unordered_map>

using namespace std;



/*
974. 和可被 K 整除的子数组

给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的（连续、非空） 子数组 的数目。

子数组 是数组的 连续 部分。
*/
class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		unordered_map<int, int> cnt;
		cnt[0]++;
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			int r = (s[i] % k + k) % k;
			res += cnt[r];
			cnt[r]++;
		}
		return res;
	}
};