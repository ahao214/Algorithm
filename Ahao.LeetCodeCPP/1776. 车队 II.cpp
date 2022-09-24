#include<vector>

using namespace std;


/*
1776. ���� II
��һ������������ n ���������ǳ���ͬ���ķ�����ʻ������һ������Ϊ n ������ cars ������ cars[i] = [positioni, speedi] ������ʾ��

positioni �ǵ� i �����͵�·���֮��ľ��루��λ���ף�����Ŀ��֤ positioni < positioni+1 ��
speedi �ǵ� i �����ĳ�ʼ�ٶȣ���λ����/�룩��
����������г��ӿ�����Ϊ���������ƶ��ĵ㡣��������ռ��ͬһ��λ��ʱ�����ǳ����������ˡ�һ�����������������ǻ�ϲ���һ�����ӣ����������ĳ�����ͬ����λ�ú���ͬ���ٶȣ��ٶ�Ϊ��������� ���� һ�������ٶȡ�

���㷵��һ������ answer ������ answer[i] �ǵ� i ��������һ����������ʱ�䣨��λ���룩�������������������һ������������ answer[i] Ϊ -1 ���𰸾���������� 10-5 ���ڡ�
*/
typedef pair<double, double> PDD;
#define x first
#define y second
class Solution {
public:

	double cross(double x1, double y1, double x2, double y2)
	{
		return x1 * y2 - x2 * y1;
	}

	double area(PDD a, PDD b, PDD c)
	{
		return cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
	}

	vector<double> getCollisionTimes(vector<vector<int>>& cars) {
		int n = cars.size();
		vector<PDD> stk(n + 1);
		vector<double> res(n);
		int top = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			auto& c = cars[i];
			PDD p(c[0], c[1]);
			while (top >= 2 && area(p, stk[top], stk[top - 1]) <= 0) top--;
			if (!top) res[i] = -1;
			else
			{
				auto& q = stk[top];
				if (p.y <= q.y) res[i] = -1;
				else res[i] = (q.x - p.x) / (p.y - q.y);
			}
			stk[++top] = p;
		}
		return res;
	}
};