#include<vector>
#include<string>

using namespace std;


/*
1507. 转变日期格式
给你一个字符串 date ，它的格式为 Day Month Year ，其中：

Day 是集合 {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} 中的一个元素。
Month 是集合 {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} 中的一个元素。
Year 的范围在 ​[1900, 2100] 之间。
请你将字符串转变为 YYYY-MM-DD 的格式，其中：

YYYY 表示 4 位的年份。
MM 表示 2 位的月份。
DD 表示 2 位的天数。
*/
class Solution {
public:
	string reformatDate(string date) {
		int year, month = 0, day;
		char month_s[4];
		sscanf(date.c_str(), "%d%*s %s %d", &day, month_s, &year);
		string month_name[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		for (int i = 0; i < 12; i++)
		{
			if (month_name[i] == month_s)
			{
				month = i + 1;
				break;
			}
		}

		char res[20];
		sprintf(res, "%04d-%02d-%02d", year, month, day);
		return res;
	}
};