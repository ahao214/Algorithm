#include<vector>
#include <map>

using namespace std;


/*
2191. 将杂乱无章的数字排序
给你一个下标从 0 开始的整数数组 mapping ，它表示一个十进制数的映射规则，mapping[i] = j 表示这个规则下将数位 i 映射为数位 j 。

一个整数 映射后的值 为将原数字每一个数位 i （0 <= i <= 9）映射为 mapping[i] 。

另外给你一个整数数组 nums ，请你将数组 nums 中每个数按照它们映射后对应数字非递减顺序排序后返回。

注意：

如果两个数字映射后对应的数字大小相同，则将它们按照输入中的 相对顺序 排序。
nums 中的元素只有在排序的时候需要按照映射后的值进行比较，返回的值应该是输入的元素本身。
*/
class Solution {
public:
	int calculate(vector<int>& mapping, int n)
	{
		if (n == 0)
			return mapping[0];
		int res = 0, unit = 1;
		while (n != 0)
		{
			int val = mapping[n % 10];
			res += val * unit;
			unit *= 10;
			n /= 10;
		}
		return res;
	}

	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
		multimap<int, int> dict;	//第一int是转换前的数字,第二个int是转换后的数字
		for (auto n : nums)
		{
			int tmp = calculate(mapping, n);
			dict.insert({ tmp,n });
		}
		vector<int> res;
		for (auto pair : dict)
		{
			res.push_back(pair.second);
		}
		return res;
	}
};