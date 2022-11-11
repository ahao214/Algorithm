#include<vector>

using namespace std;



/*
1685. 有序数组中差绝对值之和
给你一个 非递减 有序整数数组 nums 。

请你建立并返回一个整数数组 result，它跟 nums 长度相同，且result[i] 等于 nums[i] 与数组中所有其他元素差的绝对值之和。

换句话说， result[i] 等于 sum(|nums[i]-nums[j]|) ，其中 0 <= j < nums.length 且 j != i （下标从 0 开始）。
*/
class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		vector<int> res;
		for (int i = 1; i <= n; i++)
		{
			int left = i * nums[i - 1] - s[i];
			int right = s[n] - s[i] - nums[i - 1] * (n - i);
			res.push_back(left + right);
		}
		return res;
	}
};