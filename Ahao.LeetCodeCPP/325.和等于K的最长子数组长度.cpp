#include<vector>
#include <unordered_map>

using namespace std;



/*
325.和等于K的最长子数组长度
*/
class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		long prefixSum = 0;
		int res = 0;
		unordered_map<int, int> dic;
		for (int i = 0; i < nums.size(); i++)
		{
			prefixSum += nums[i];
			if (prefixSum == k)
				res = i + 1;
			if (dic.count(prefixSum - k))
				res = max(res, i - dic[prefixSum - k]);
			if (!dic.count(prefixSum))
				dic[prefixSum] = i;
		}
		return res;
	}
}

