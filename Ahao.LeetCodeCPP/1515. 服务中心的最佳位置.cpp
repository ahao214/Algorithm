#include<vector>

using namespace std;


/*
1515. �������ĵ����λ��
һ�ҿ�ݹ�˾ϣ�����³��н����µķ������ġ���˾ͳ���˸ó������пͻ��ڶ�ά��ͼ�ϵ����꣬��ϣ���ܹ��Դ�Ϊ����Ϊ�µķ�������ѡַ��ʹ�������� �����пͻ���ŷ����þ�����ܺ���С ��

����һ������ positions ������ positions[i] = [xi, yi] ��ʾ�� i ���ͻ��ڶ�ά��ͼ�ϵ�λ�ã����ص����пͻ��� ŷ����þ������С�ܺ� ��

���仰˵������Ϊ��������ѡַ����λ�õ����� [xcentre, ycentre] ��Ҫʹ����Ĺ�ʽȡ����Сֵ��

����ʵֵ����� 10-5֮�ڵĴ𰸽���������ȷ�𰸡�
*/
class Solution {
public:
	vector<vector<int>> points;
	double getSum(double x, double y)
	{
		double sum = 0;
		for (auto& p : points)
		{
			double a = p[0], b = p[1];
			sum += sqrt((x - a) * (x - a) + (y - b) * (y - b));
		}
		return sum;
	}

	double calc(double x)
	{
		double l = 0, r = 100;
		while (r - l > 1e-7)
		{
			double y1 = l + (r - l) / 3, y2 = l + (r - l) / 3 * 2;
			if (getSum(x, y1) >= getSum(x, y2)) l = y1;
			else r = y2;
		}
		return getSum(x, r);
	}

	double getMinDistSum(vector<vector<int>>& positions) {
		points = positions;
		double l = 0, r = 100;
		while (r - l > 1e-7)
		{
			double x1 = l + (r - l) / 3, x2 = l + (r - l) / 3 * 2;
			if (calc(x1) >= calc(x2)) l = x1;
			else r = x2;
		}
		return calc(r);
	}
};