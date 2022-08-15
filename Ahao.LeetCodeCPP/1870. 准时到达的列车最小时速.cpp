#include<vector>

using namespace std;



/*
1870. ׼ʱ������г���Сʱ��
����һ�������� hour ����ʾ�㵽��칫�ҿ��õ���ͨ��ʱ�䡣Ҫ����칫�ң�����밴����������� n ���г��������һ������Ϊ n ���������� dist ������ dist[i] ��ʾ�� i ���г�����ʻ���루��λ��ǧ�ף���

ÿ���г���ֻ�������㷢���������������Ҫ�������г�֮��ȴ�һ��ʱ�䡣

���磬�� 1 ���г���Ҫ 1.5 Сʱ����������ٵȴ� 0.5 Сʱ������ڵ� 2 Сʱ�����ĵ� 2 ���г���
������������׼ʱ����칫����Ҫ��ȫ���г��� ��С������ ʱ�٣���λ��ǧ��ÿСʱ��������޷�׼ʱ����򷵻� -1 ��

���ɵĲ���������֤�𰸲����� 107 ���� hour �� С�������������λ���� ��
*/
class Solution {
public:
	double get(vector<int>& dist, int mid)
	{
		double res = 0;
		for (int i = 0; i + 1 < dist.size(); i++)
		{
			res += (dist[i] + mid - 1) / mid;
		}
		return res + (double)dist.back() / mid;
	}

	int minSpeedOnTime(vector<int>& dist, double hour) {
		int left = 1, right = 2e7;
		while (left < right)
		{
			int mid = left + right >> 1;
			if (get(dist, mid) <= hour)
				right = mid;
			else
				left = mid + 1;
		}
		if (right == 2e7)
			return -1;
		return right;
	}

};