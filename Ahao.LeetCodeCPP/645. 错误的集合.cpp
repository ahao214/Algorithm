#include<vector>

using namespace std;


/*
645. ´íÎóµÄ¼¯ºÏ
*/
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> res(2);
		for (auto x : nums)
		{
			int k = abs(x);
			if (nums[k - 1] < 0)
				res[0] = k;
			nums[k - 1] *= -1;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0 && i + 1 != res[0])
				res[1] = i + 1;
		}
		return res;
	}
};