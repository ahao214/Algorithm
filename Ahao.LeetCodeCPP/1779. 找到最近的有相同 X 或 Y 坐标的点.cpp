#include<vector>

using namespace std;


/*
1779. �ҵ����������ͬ X �� Y ����ĵ�
������������ x �� y ����ʾ����һ���ѿ�������ϵ�µ� (x, y) ����ͬʱ����ͬһ������ϵ�¸���һ������ points ������ points[i] = [ai, bi] ��ʾ�� (ai, bi) ����һ���㡣��һ�����������ڵ�λ������ͬ�� x ���������ͬ�� y ����ʱ�����ǳ�������� ��Ч�� ��

�뷵�ؾ����㵱ǰλ�� �����پ��� ����� ��Ч ����±꣨�±�� 0 ��ʼ��������ж���������Ч�㣬�뷵���±� ��С ��һ�������û����Ч�㣬�뷵�� -1 ��

������ (x1, y1) �� (x2, y2) ֮��� �����پ��� Ϊ abs(x1 - x2) + abs(y1 - y2) ��
*/
class Solution {
public:
	int getDis(vector<int> a, vector<int>& b)
	{
		return abs(a[0] - b[0]) + abs(a[1] - b[1]);
	}

	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int res = -1;
		for (int i = 0; i < points.size(); i++)
		{
			if (points[i][0] == x || points[i][1] == y)
			{
				if (res == -1 || getDis({ x,y }, points[res]) > getDis({ x,y }, points[i]))
					res = i;
			}
		}
		return res;
	}
};
