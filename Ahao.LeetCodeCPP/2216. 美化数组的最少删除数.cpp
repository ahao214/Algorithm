#include<vector>
#include <stack>

using namespace std;


/*
2216. 美化数组的最少删除数

给你一个下标从 0 开始的整数数组 nums ，如果满足下述条件，则认为数组 nums 是一个 美丽数组 ：

nums.length 为偶数
对所有满足 i % 2 == 0 的下标 i ，nums[i] != nums[i + 1] 均成立
注意，空数组同样认为是美丽数组。

你可以从 nums 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 不变 。

返回使 nums 变为美丽数组所需删除的 最少 元素数目。
*/
class Solution {
public:
	int minDeletion(vector<int>& nums) {
		if (nums.empty())
			return 0;

		stack<int> stk;
		int index = 0, res = 0;
		stk.push(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			if (index % 2 == 0 && nums[i] != stk.top())
			{
				stk.push(nums[i]);
				index++;
			}
			else if (index % 2 == 0 && nums[i] == stk.top())
			{
				res++;
			}
			else
			{
				stk.push(nums[i]);
				index++;
			}
		}
		//stk是奇数
		if (stk.size() % 2 != 0)
			res++;
		return res;
	}
};