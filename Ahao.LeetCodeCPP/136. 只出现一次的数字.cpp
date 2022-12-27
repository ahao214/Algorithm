#include<vector>

using namespace std;


/*
136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，
其余每个元素均出现两次。找出那个只出现了一次的元素。
*/
//a ^ a = 0  0 ^ a = a 
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto x : nums)
			res ^= x;
		return res;
	}
};