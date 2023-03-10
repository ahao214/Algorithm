#include<vector>
#include<unordered_map>


using namespace std;


/*
1590. 使数组和能被 P 整除

给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。

子数组 定义为原数组中连续的一组元素。
*/
class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		unordered_map<int, int> Map;
		Map[0] = -1;
		long totalSum = 0;
		for (auto a : nums)
			totalSum = (totalSum + a) % p;
		long r0 = totalSum % p;
		if (r0 == 0) return 0;

		int presum = 0;
		int ret = INT_MAX;
		for (int j = 0; j < nums.size(); j++)
		{
			presum = (presum + nums[j]) % p;
			int r = presum % p;
			int dr = (r - r0 + p) % p;

			if (Map.find(dr) != Map.end())
			{
				int i = Map[dr] + 1;
				ret = min(ret, j - i + 1);
			}
			Map[presum % p] = j;
		}
		if (ret < nums.size())
			return ret;
		else
			return -1;
	}
};





class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		int x = 0;
		for (auto num : nums) {
			x = (x + num) % p;
		}
		if (x == 0) {
			return 0;
		}
		unordered_map<int, int> index;
		int y = 0, res = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			index[y] = i; // f[i] mod p = y，因此哈希表记录 y 对应的下标为 i
			y = (y + nums[i]) % p;
			if (index.count((y - x + p) % p) > 0) {
				res = min(res, i - index[(y - x + p) % p] + 1);
			}
		}
		return res == nums.size() ? -1 : res;
	}
};
