#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

/*
1403. 非递增顺序的最小子序列
*/
class Solution {
public:
	vector<int> minSubsequence(vector<int>& nums) {
		int total = accumulate(nums.begin(), nums.end(), 0);
		sort(nums.begin(), nums.end());
		vector<int> ans;
		int curr = 0;
		for (int i = nums.size() - 1; i >= 0; --i) {
			curr += nums[i];
			ans.emplace_back(nums[i]);
			if (total - curr < curr) {
				break;
			}
		}
		return ans;
	}
};
