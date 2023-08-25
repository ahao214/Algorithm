#include<vector>
#include <string>

using namespace std;


/*
228. 汇总区间

给定一个  无重复元素 的 有序 整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，
并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
*/
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.size() == 0)
			return {};
		int j = 0;
		string str;
		vector<string> res;
		for (int i = 0; i < nums.size(); i++)
		{
			j = i;
			while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1)
			{
				j++;
			}
			if (j > i)
			{
				str = to_string(nums[i]) + "->" + to_string(nums[j]);
			}
			else
			{
				str = to_string(nums[j]);
			}
			res.push_back(str);
			str.clear();
			i = j;
		}
		return res;
	}
};



/*
228. 汇总区间
给定一个  无重复元素 的 有序 整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，
并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
*/
class Solution {
public:
	string rangeToString(int st, int ed)
	{
		if (st == ed) return to_string(st);
		return to_string(st) + "->" + to_string(ed);
	}

	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		if (nums.empty()) return res;
		int st = nums[0], ed = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int x = nums[i];
			if (x > ed + 1)
			{
				res.push_back(rangeToString(st, ed));
				st = ed = x;
			}
			else
			{
				ed++;
			}
		}
		res.push_back(rangeToString(st, ed));
		return res;
	}
};



class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		int i = 0;
		int n = nums.size();
		while (i < n) {
			int low = i;
			i++;
			while (i < n && nums[i] == nums[i - 1] + 1) {
				i++;
			}
			int high = i - 1;
			string temp = to_string(nums[low]);
			if (low < high) {
				temp.append("->");
				temp.append(to_string(nums[high]));
			}
			ret.push_back(move(temp));
		}
		return ret;
	}
};

