#include<vector>
#include<unordered_map>

using namespace std;



/*
1748. 唯一元素的和
给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。

请你返回 nums 中唯一元素的 和 。
*/
class Solution {
public:
	int sumOfUnique(vector<int>& nums) {
		unordered_map<int, int> hash;
		for (auto x : nums) hash[x]++;
		int res = 0;
		for (auto [k, v] : hash)
			if (v == 1)
				res += k;
		return res;
	}
};