#include<vector>
#include<algorithm>

using namespace std;


/*
976. 三角形的最大周长

给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回 0。
*/
class Solution {
public:
	int largestPerimeter(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 2; i--)
		{
			int a = nums[i - 2], b = nums[i - 1], c = nums[i];
			if (a + b > c)
				return a + b + c;
		}
		return 0;
	}
};