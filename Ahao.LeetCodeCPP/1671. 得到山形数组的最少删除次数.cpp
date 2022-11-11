#include<vector>


using namespace std;


/*
1671. 得到山形数组的最少删除次数
我们定义 arr 是 山形数组 当且仅当它满足：

arr.length >= 3
存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
给你整数数组 nums​ ，请你返回将 nums 变成 山形状数组 的​ 最少 删除次
*/
class Solution {
public:
	int minimumMountainRemovals(vector<int>& nums) {
		int n = nums.size();
		vector<int> f(n), g(n);
		for (int i = 0; i < n; i++)
		{
			f[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					f[i] = max(f[i], f[j] + 1);
			}
		}

		for (int i = n - 1; i >= 0; i--)
		{
			g[i] = 1;
			for (int j = n - 1; j >= i; j--)
			{
				if (nums[j] < nums[i])
					g[i] = max(g[i], g[j] + 1);
			}
		}

		int res = 0;
		for (int k = 0; k < n; k++)
		{
			if (f[k] > 1 && g[k] > 1)
				res = max(res, f[k] + g[k] - 1);
		}
		return n - res;
	}
};
