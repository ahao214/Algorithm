using namespace std;
#include <vector>

#pragma region 68. 0到n-1中缺失的数字

/*
一个长度为 n−1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围 0 到 n−1 之内。

在范围 0 到 n−1 的 n 个数字中有且只有一个数字不在该数组中，请找出这个数字。

数据范围
1≤n≤1000
*/

#pragma endregion

class Solution {
public:
	int getMissingNumber(vector<int>& nums) {
		int res = 0;
		bool flag = false;
		for (int i = 0; i < nums.size(); i++) {
			if (i != nums[i]) {
				res = i;
				flag = true;
				break;
			}
		}
		if (flag == true)
			return res;
		else
			return nums.size();
	}
};