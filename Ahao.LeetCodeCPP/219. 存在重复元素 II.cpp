#include<vector>
#include<set>

using namespace std;


/*
219. 存在重复元素 II
时间O(N) 空间O(1)
*/
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		set<int> st;
		for (int i = 0; i < nums.size(); i++)
		{
			if (st.count(nums[i]))
				return true;
			st.insert(nums[i]);
			if (st.size() > k)
				st.erase(nums[i - k]);
		}
		return false;
	}
};