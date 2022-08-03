#include<vector>

using namespace std;

/*
198. ¥Úº“ΩŸ…·
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int rob = nums[0], norob = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			int robTmp = rob, norobTmp = norob;
			norob = max(robTmp, norobTmp);
			rob = norobTmp + nums[i];
		}
		return max(rob, norob);
	}
};
