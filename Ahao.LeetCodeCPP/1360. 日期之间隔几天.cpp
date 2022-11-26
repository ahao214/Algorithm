#include<vector>
#include <string>

using namespace std;



/*
1360. 日期之间隔几天
请你编写一个程序来计算两个日期之间隔了多少天。

日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。
*/
class Solution {
public:
	int daysBetweenDates(string date1, string date2) {
		//分别求出从题目给定的起始日期到date1和到date2的天数d1和d2
		//再求出d1和d2的差值的绝对值
		return abs(get(date1) - get(date2));
	}

	bool isLeap(int year)
	{
		return year % 100 && year % 4 == 0 || year % 400 == 0;
	}

	int mDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int get(string date)
	{
		int year, month, day;
		sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

		int days = 0;
		for (int i = 1971; i < year; i++)
			days += 365 + isLeap(i);

		for (int i = 1; i < month; i++)
		{
			if (i == 2) days += 28 + isLeap(year);
			else days += mDays[i];
		}

		return days + day;
	}
};
