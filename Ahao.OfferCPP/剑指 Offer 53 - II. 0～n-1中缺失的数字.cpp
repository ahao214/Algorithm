#include<vector>

using namespace std;


/*
剑指 Offer 53 - II. 0～n-1中缺失的数字
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int i = 0, j = nums.size() - 1;
		while (i <= j)
		{
			int mid = (i + j) >> 1;
			if (nums[mid] == mid) i = mid + 1;
			else if (nums[mid] > mid) j = mid - 1;
		}
		return i;
	}
};

