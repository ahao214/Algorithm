#include<vector>

using namespace std;


/*
1701. ƽ���ȴ�ʱ��
��һ��������ֻ��һλ��ʦ������һ���˿����� customers ������ customers[i] = [arrivali, timei] ��

arrivali �ǵ� i λ�˿͵����ʱ�䣬����ʱ�䰴 �ǵݼ� ˳�����С�
timei �Ǹ��� i λ�˿�������Ҫ��ʱ�䡣
��һλ�˿͵���ʱ���������Ķ�������ʦ����ʦһ�����е�ʱ��Ϳ�ʼ����λ�˿͵Ĳˡ�ÿλ�˿ͻ�һֱ�ȴ�����ʦ������Ķ�������ʦͬʱֻ����һ���˵Ķ�������ʦ���ϸ��� ����������˳�� ���ˡ�

���㷵�����й˿���Ҫ�ȴ��� ƽ�� ʱ�䡣���׼������� 10-5 ��Χ���ڣ�����Ϊ��ȷ�����
*/
class Solution {
public:
	double averageWaitingTime(vector<vector<int>>& customers) {
		double sum = 0, t = 0;
		for (auto c : customers)
		{
			//arrT����ʱ�� timei����ʱ��
			int arrT = c[0], timei = c[1];
			/*
			��ʦ������һ���������õ���ʱ��>=��һλ�ͻ��ĵ���ʱ��
			��ʦ����ֱ�ӿ�ʼ����ͻ�
			*/
			if (arrT >= t)
			{
				sum += timei;
				t = arrT + timei;
			}
			else
			{
				sum += t - arrT + timei;
				t += timei;
			}
		}
		return sum / customers.size();
	}
};