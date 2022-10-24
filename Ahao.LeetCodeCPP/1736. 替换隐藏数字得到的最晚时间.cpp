#include<vector>
#include<string>


using namespace std;



/*
1736. 替换隐藏数字得到的最晚时间
给你一个字符串 time ，格式为 hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。

有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。

替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。
*/
class Solution {
public:
	bool check(string time, char str[])
	{
		for (int i = 0; i < 5; i++)
		{
			if (time[i] == str[i] || time[i] == '?')continue;
			return false;
		}
		return true;
	}

	string maximumTime(string time) {
		for (int i = 23; i >= 0; i--)
		{
			for (int j = 59; j >= 0; j--)
			{
				char str[20];
				sprintf(str, "%02d:%02d", i, j);
				if (check(time, str))
					return str;
			}
		}
		return "";
	}
};

