#include<vector>
#include <string>

using namespace std;


/*
168. Excel表列名称

给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
*/

class Solution {
public:
	string convertToTitle(int columnNumber) {
		string res;
		while (columnNumber)
		{
			int remainder = columnNumber % 26;
			if (remainder == 0)
			{
				remainder = 26;
				columnNumber -= 26;
			}
			res += remainder + 'A' - 1;
			columnNumber /= 26;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
