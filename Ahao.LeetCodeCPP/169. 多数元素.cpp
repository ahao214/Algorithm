#include<vector>

using namespace std;


/*
169. 多数元素

给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int t, c = 0;
		for (auto& x : nums)
		{
			if (c == 0)
				t = x, c = 1;
			else if (x == t)
				c++;
			else
				c--;
		}
		return t;
	}
};