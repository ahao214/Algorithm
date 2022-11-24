#include<vector>

using namespace std;


/*
1458. 两个子序列的最大点积
给你两个数组 nums1 和 nums2 。

请你返回 nums1 和 nums2 中两个长度相同的 非空 子序列的最大点积。

数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，[2,3,5] 是 [1,2,3,4,5] 的一个子序列而 [1,5,3] 不是。
*/
class Solution {
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		vector<vector<int>> f(n + 1, vector<int>(m + 1, -0x3f3f3f3f));

		for (int i = 0; i <= n; i++)
			f[i][0] = 0;
		for (int i = 0; i <= m; i++)
			f[0][i] = 0;

		int res = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				int t = f[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1];
				res = max(res, t);
				f[i][j] = max(f[i][j], t);
			}
		}
		return res;
	}
};
