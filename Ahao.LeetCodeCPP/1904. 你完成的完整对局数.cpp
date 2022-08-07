#include<vector>
#include<string>

using namespace std;


/*
1904. ����ɵ������Ծ���
һ���µ����ߵ�����Ϸ�ڽ��ڷ������ڸõ�����Ϸ�У��� ���� Ϊ���ڹ滮����ʱ��Ϊ 15 ���� ����Ϸ�Ծ֡�����ζ�ţ��� HH:00��HH:15��HH:30 �� HH:45 �����Ὺʼһ���µĶԾ֣����� HH ��һ���� 00 �� 23 ��������ʾ����Ϸ��ʹ�� 24 Сʱ�Ƶ�ʱ�� ������һ���������ʱ���� 00:00 �������ʱ���� 23:59 ��

���������ַ��� startTime �� finishTime �������� "HH:MM" ��ʽ���ֱ��ʾ�� ���� �� �˳� ��Ϸ��ȷ��ʱ�䣬�������������Ϸ�Ự�ڼ䣬����ɵ� �����ԾֵĶԾ��� ��

���磬��� startTime = "05:20" �� finishTime = "05:59" ������ζ���������ɴ� 05:30 �� 05:45 ��һ�������Ծ֡�����û����ɴ� 05:15 �� 05:30 �������Ծ֣���Ϊ�����ڶԾֿ�ʼ��������Ϸ��ͬʱ����Ҳû����ɴ� 05:45 �� 06:00 �������Ծ֣���Ϊ�����ڶԾֽ���ǰ�˳�����Ϸ��
��� finishTime ���� startTime �����ʾ�����˸�ͨ����Ҳ���Ǵ� startTime ����ҹ���ٴ���ҹ�� finishTime����

�������Ǵ� startTime ������Ϸ������ finishTime �˳���Ϸ������㲢��������ɵ� �����ԾֵĶԾ��� ��
*/
class Solution {
public:
	int get(string s)
	{
		int h, m;
		sscanf(s.c_str(), "%d:%d", &h, &m);
		return h * 60 + m;
	}

	int numberOfRounds(string loginTime, string logoutTime) {
		int x = get(loginTime), y = get(logoutTime);
		if (x > y) y += 24 * 60;
		x = (x + 14) / 15, y /= 15;
		return y - x;
	}

};

