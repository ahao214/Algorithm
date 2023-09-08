#include<vector>
#include <string>
#include <algorithm>

using namespace std;

/*
179. 最大数

给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/



class Solution {
	static bool cmp(const int& x, const int& y)
	{
		string a = to_string(x), b = to_string(y);
		return a + b > b + a;
	}
public:
	string largestNumber(vector<int>& nums) {
		string res;
		sort(nums.begin(), nums.end(), cmp);
		for (auto& num : nums)
		{
			res += to_string(num);
		}
		if (res[0] == '0')
			return "0";
		return res;
	}
};