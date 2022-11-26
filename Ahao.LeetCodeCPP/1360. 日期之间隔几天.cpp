#include<vector>
#include <string>

using namespace std;



/*
1360. ����֮�������
�����дһ��������������������֮����˶����졣

�������ַ�����ʽ��������ʽΪ YYYY-MM-DD����ʾ����ʾ��
*/
class Solution {
public:
	int daysBetweenDates(string date1, string date2) {
		//�ֱ��������Ŀ��������ʼ���ڵ�date1�͵�date2������d1��d2
		//�����d1��d2�Ĳ�ֵ�ľ���ֵ
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
