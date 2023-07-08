#include<vector>

using namespace std;




/*
315. 计算右侧小于当前元素的个数

给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
*/
class Solution {
public:
	int n = 20001;
	vector<int> tr;
	int lowbit(int x)
	{
		return x & -x;
	}

	int query(int x)
	{
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	void add(int x, int v)
	{
		for (int i = x; i <= n; i += lowbit(i))
			tr[i] += v;
	}

	vector<int> countSmaller(vector<int>& nums) {
		tr.resize(n + 1);
		vector<int> res(nums.size());
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			int x = nums[i] + 10001;
			res[i] = query(x - 1);
			add(x, 1);
		}
		return res;
	}
};