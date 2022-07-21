#include<vector>

using namespace std;

/*
1658. 将 x 减到 0 的最小操作数
*/
/*
给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。
*/
/*
nums = [1,1,4,2,3] x = 5
1、先求出数组的前缀和、后缀和
前缀和 = [1,2,6,8,11]
后缀和 = [11,10,9,5,3]
2、取出前缀和中0个数字，即表示从前缀和中取出0个元素，value = 0，从后缀和中末尾开始，查询是否存在(x - value)的值，如果存在，则记录下后缀和的位置
3、取出前缀和中第1个数字，value= 1，从后缀和中末尾开始，查询是否存在(x - value)的值，如果存在，则记录下后缀和的位置
*/

class Solution {
public:
	int binarySearch(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (target == nums[mid])
			{
				return mid;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return -1;
	}


	int minOperations(vector<int>& nums, int x) {
		vector<int> suml(nums.size() + 1);
		vector<int> sumr(nums.size() + 1);

		suml[0] = sumr[0];

		//前缀和
		for (int i = 0; i < nums.size(); i++)
		{
			suml[i + 1] = suml[i] + nums[i];
		}

		//后缀和
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			sumr[nums.size() - i] = sumr[nums.size() - i - 1] + nums[i];
		}

		int res = -1;
		for (int i = 0; i < suml.size(); i++)
		{
			int j = binarySearch(sumr, x - suml[i]);
			if (j == -1)
				continue;
			if (i + j > nums.size())
				continue;
			if (res == -1 || res > i + j)
				res = i + j;
		}

		return res;
	}
};
