#include<vector>
#include <string>

using namespace std;


/*
1556. 千位分隔数
给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。
*/
class Solution {
public:
	string thousandSeparator(int n) {
		string num = to_string(n);
		string res;
		for (int i = num.size() - 1, j = 0; i >= 0; i--, j++)
		{
			if (j % 3 == 0 && j)
				res += '.';
			res += num[i];
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
