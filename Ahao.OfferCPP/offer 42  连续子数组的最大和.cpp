#include<vector>

using namespace std;


/*
offer 42  连续子数组的最大和
*/
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> nums) {
		if (nums.empty()) return 0;
		int ans = INT_MIN;
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (sum <= 0)
			{
				sum = nums[i];
			}
			else
			{
				sum += nums[i];
			}
			ans = max(ans, sum);
		}
		return ans;
	}
};