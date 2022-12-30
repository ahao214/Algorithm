#include<vector>
#include <unordered_map>

using namespace std;


/*
560. 和为 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。
*/
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> hash;
		hash[0] = 1;
		int res = 0, s = 0;
		for (auto x : nums)
		{
			s += x;
			res += hash[s - k];
			hash[s]++;
		}
		return res;
	}
};



class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int res = 0, sum = 0;
		unordered_map<int, int> dict;
		dict[0] = 1;
		for (int n : nums) {
			sum += n;
			if (dict.count(sum - k)) {
				res += dict[sum - k];
			}
			dict[sum]++;
		}
		return res;
	}
};
