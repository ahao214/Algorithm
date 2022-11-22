#include<vector>
#include <deque>

using namespace std;


/*
1499. ���㲻��ʽ�����ֵ
����һ������ points ��һ������ k ��������ÿ��Ԫ�ض���ʾ��άƽ���ϵĵ�����꣬�����պ����� x ��ֵ��С��������Ҳ����˵ points[i] = [xi, yi] �������� 1 <= i < j <= points.length ��ǰ���£� xi < xj �ܳ�����

�����ҳ� yi + yj + |xi - xj| �� ���ֵ������ |xi - xj| <= k �� 1 <= i < j <= points.length��

��Ŀ�������ݱ�֤���ٴ���һ���ܹ����� |xi - xj| <= k �ĵ㡣
*/
class Solution {
public:
	/*
	yi + yj + |xi - xj| = yi + yj + xj - xi =(yi - xi) + (yj + xj)
		������������ֵ
	*/
	int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		deque<int> q;	//��������
		int res = INT_MIN;

		for (int i = 0; i < points.size(); i++)
		{
			int x = points[i][0], y = points[i][1];
			while (q.size() && x - points[q.front()][0] > k) q.pop_front();
			if (q.size())
			{
				int t = q.front();
				res = max(res, x + y + points[t][1] - points[t][0]);
			}
			while (q.size() && points[q.back()][1] - points[q.back()][0] <= y - x)
				q.pop_back();
			q.push_back(i);
		}
		return res;
	}
};

