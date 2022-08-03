#include<vector>
#include<unordered_map>

using namespace std;


/*
2150. 找出数组中的所有孤独数字
给你一个整数数组 nums 。如果数字 x 在数组中仅出现 一次 ，且没有 相邻 数字（即，x + 1 和 x - 1）出现在数组中，则认为数字 x 是 孤独数字 。

返回 nums 中的 所有 孤独数字。你可以按 任何顺序 返回答案。
*/
class Solution {
public:
	vector<int> findLonely(vector<int>& nums) {
		unordered_map<int, int> cnt;
		for (auto x : nums)
			cnt[x]++;
		vector<int> res;
		for (auto x : nums)
		{
			if (cnt[x] == 1 && !cnt.count(x - 1) && !cnt.count(x + 1))
				res.push_back(x);
		}
		return res;
	}

};
