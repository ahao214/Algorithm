#include<vector>

using namespace std;


/*
1991. 找到数组的中间位置
给你一个下标从 0 开始的整数数组 nums ，请你找到 最左边 的中间位置 middleIndex （也就是所有可能中间位置下标最小的一个）。

中间位置 middleIndex 是满足 nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1] 的数组下标。

如果 middleIndex == 0 ，左边部分的和定义为 0 。类似的，如果 middleIndex == nums.length - 1 ，右边部分的和定义为 0 。

请你返回满足上述条件 最左边 的 middleIndex ，如果不存在这样的中间位置，请你返回 -1 。
*/
class Solution {
public:
	int findMiddleIndex(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n + 2);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + nums[i - 1];
		for (int i = 1; i <= n; i++)
			if (s[i - 1] == s[n] - s[i])
				return i - 1;
		return -1;
	}
};
