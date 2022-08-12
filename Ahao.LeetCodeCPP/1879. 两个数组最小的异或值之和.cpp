#include<vector>

using namespace std;


/*
1879. 两个数组最小的异或值之和
给你两个整数数组 nums1 和 nums2 ，它们长度都为 n 。

两个数组的 异或值之和 为 (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) （下标从 0 开始）。

比方说，[1,2,3] 和 [3,2,1] 的 异或值之和 等于 (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4 。
请你将 nums2 中的元素重新排列，使得 异或值之和 最小 。

请你返回重新排列之后的 异或值之和 。
*/
class Solution {
public:
	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), INF = 1e9;
		vector<int> f(1 << n, INF);
		f[0] = 0;
		for (int i = 1; i < 1 << n; i++)
		{
			int s = 0;
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
					s++;
			}
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
					f[i] = min(f[i], f[i - (1 << j)] + (nums2[j] ^ nums1[s - 1]));
			}
		}
		return f[(1 << n) - 1];
	}

};