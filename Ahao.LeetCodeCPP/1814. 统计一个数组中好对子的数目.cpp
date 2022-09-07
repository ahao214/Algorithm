#include<vector>
#include<string>
#include <unordered_map>

using namespace std;


/*
1814. 统计一个数组中好对子的数目
给你一个数组 nums ，数组中只包含非负整数。定义 rev(x) 的值为将整数 x 各个数字位反转得到的结果。比方说 rev(123) = 321 ， rev(120) = 21 。我们称满足下面条件的下标对 (i, j) 是 好的 ：

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
请你返回好下标对的数目。由于结果可能会很大，请将结果对 109 + 7 取余 后返回。
*/
class Solution {
public:
	int countNicePairs(vector<int>& nums) {
		unordered_map<int, int> cnt;
		for (auto t : nums)
		{
			int x = t;
			string s = to_string(x);
			reverse(s.begin(), s.end());
			int y = stoi(s);
			cnt[x - y]++;
		}
		const int MOD = 1e9 + 7;
		int res = 0;
		for (auto [k, v] : cnt)
			res = (res + (long long)v * (v - 1) / 2) % MOD;
		return res;
	}
};

