#include<vector>
#include <string>

using namespace std;


/*
171. Excel 表列序号

给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。
*/


class Solution {
public:
	int titleToNumber(string columnTitle) {
		int res = 0;
		for (auto& c : columnTitle)
		{
			res = res * 26 - 'A' + c + 1;
		}
		return res;
	}
};