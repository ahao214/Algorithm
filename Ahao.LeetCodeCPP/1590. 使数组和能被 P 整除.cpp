#include<vector>
#include<unordered_map>


using namespace std;


/*
1590. 使数组和能被 P 整除
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