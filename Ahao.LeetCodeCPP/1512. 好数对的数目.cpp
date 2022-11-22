#include<vector>
#include <unordered_map>

using namespace std;


/*
1512. 好数对的数目
给你一个整数数组 nums 。

如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

返回好数对的数目。
*/
class Solution {
public:
	/*
	统计每种数字的个数
	*/
	int numIdenticalPairs(vector<int>& nums) {
		unordered_map<int, int> cnt;
		for (auto x : nums) cnt[x]++;
		int res = 0;
		for (auto [v, c] : cnt)
			res += c * (c - 1) / 2;
		return res;
	}
};