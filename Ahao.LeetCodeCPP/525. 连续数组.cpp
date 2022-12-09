#include<vector>
#include <unordered_map>

using namespace std;



/*
525. 连续数组
给定一个二进制数组nums , 找到含有相同数量的0和1 的最长连续子数组，并返回该子数组的长度。
*/
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int, int> hash;
		hash[0] = -1;
		int res = 0, s = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			s += nums[i] ? 1 : -1;
			if (!hash.count(s)) hash[s] = i;
			else res = max(res, i - hash[s]);
		}
		return res;
	}
};
