#include<vector>

using namespace std;



/*
1558. 得到目标数组的最少函数调用次数

给你一个与 nums 大小相同且初始值全为 0 的数组 arr ，请你调用以上函数得到整数数组 nums 。

请你返回将 arr 变成 nums 的最少函数调用次数。

答案保证在 32 位有符号整数以内。
arr=[0,0,0] 变成数组 nums = [2,3,1]
操作的行为有：对arr数组中的某个数加1，或对arr数组中的所有数都乘以2
*/
class Solution {
public:
	int minOperations(vector<int>& nums) {
		int k = 0, os = 0;
		for (auto x : nums)
		{
			int bits = 0, ones = 0;
			while (x)
			{
				if (x & 1) ones++;
				bits++;
				x >>= 1;
			}
			k = max(k, bits), os += ones;
		}
		return os + k - 1;
	}
};
