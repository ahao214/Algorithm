#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;



/*
128. 最长连续序列

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int res = 0;
		unordered_map<int, int> tr_left, tr_right;
		for (auto x : nums)
		{
			int left = tr_right[x - 1];
			int right = tr_left[x + 1];
			tr_left[x - left] = max(tr_left[x - left], left + 1 + right);
			tr_right[x + right] = max(tr_right[x + right], left + 1 + right);
			res = max(res, left + 1 + right);
		}
		return res;
	}
};


class Solution {
public:
	/*
	Times:O(n)
	Space:O(n)
	*/
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> st(nums.begin(), nums.end());
		int res = 0;
		for (int num : nums)
		{
			if (!st.count(num - 1))
			{
				int x = num + 1;
				while (st.count(x))
					x++;
				res = max(res, x - num);
			}
		}
		return res;
	}
};