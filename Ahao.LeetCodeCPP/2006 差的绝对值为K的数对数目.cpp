#include<vector>

using namespace std;


/*
2006 差的绝对值为K的数对数目
*/
class Solution {
public:
	int countKDifference(vector<int>& nums, int k) {
		int n = nums.size(), res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (abs(nums[i] - nums[j]) == k)
					res++;
			}
		}
		return res;
	}
};