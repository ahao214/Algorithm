#include<vector>
#include<string>


using namespace std;



/*
1736. �滻�������ֵõ�������ʱ��
����һ���ַ��� time ����ʽΪ hh:mm��Сʱ�����ӣ�������ĳ��λ���ֱ����أ��� ? ��ʾ����

��Ч��ʱ��Ϊ 00:00 �� 23:59 ֮�������ʱ�䣬���� 00:00 �� 23:59 ��

�滻 time �����ص����֣���������Եõ���������Чʱ�䡣
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

