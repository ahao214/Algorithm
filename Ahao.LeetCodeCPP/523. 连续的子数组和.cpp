#include<vector>
#include <unordered_set>

using namespace std;



/*
523. 连续的子数组和
*/
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		if (!k)
		{
			for (int i = 1; i < nums.size(); i++)
			{
				if (!nums[i - 1] && !nums[i])
					return true;
			}
			return false;
		}
		int n = nums.size();
		//前缀和数组
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + nums[i - 1];
		unordered_set<int> hash;
		for (int i = 2; i <= n; i++)
		{
			hash.insert(s[i - 2] % k);
			if (hash.count(s[i] % k))
				return true;
		}
		return false;
	}
};
