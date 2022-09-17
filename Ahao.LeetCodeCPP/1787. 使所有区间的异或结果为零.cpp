#include<vector>

using namespace std;



/*
1787. 使所有区间的异或结果为零
给你一个整数数组 nums​​​ 和一个整数 k​​​​​ 。区间 [left, right]（left <= right）的 异或结果 是对下标位于 left 和 right（包括 left 和 right ）之间所有元素进行 XOR 运算的结果：nums[left] XOR nums[left+1] XOR ... XOR nums[right] 。

返回数组中 要更改的最小元素数 ，以使所有长度为 k 的区间异或结果等
*/
class Solution {
public:
	const int M = 1024, INF = 1e8;
	int s[1024];

	int minChanges(vector<int>& nums, int k) {
		int n = nums.size(), m = (n + k - 1) / k;
		vector<vector<int>> f(k + 1, vector<int>(M, INF));
		f[0][0] = 0;
		int sum = 0, minv = INF;
		for (int i = 1; i <= k; i++)
		{
			memset(s, 0, sizeof s);
			int len = m;
			if (n % k && n % k < i) len--;

			for (int j = 0; j < len; j++)
			{
				s[nums[j * k + i - 1]]++;
			}

			int maxv = 0;
			for (int j = 0; j < M; j++)
			{
				if (s[j])
					maxv = max(maxv, s[j]);
			}
			sum += len - maxv, minv = min(minv, maxv);

			for (int j = 0; j < M; j++)
			{
				for (int u = 0; u < len; u++)
				{
					int x = nums[u * k + i - 1], cost = len - s[x];
					f[i][j] = min(f[i][j], f[i - 1][j ^ x] + cost);
				}
			}
		}
		return min(sum + minv, f[k][0]);
	}
};
