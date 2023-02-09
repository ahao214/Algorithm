#include<vector>
#include <string>
#include<unordered_set>

using namespace std;


/*
874. ģ�����߻�����

��������һ�����޴�С�� XY ����ƽ�������ߣ��ӵ� (0, 0) ����ʼ���������򱱷����û����˿��Խ��������������͵����� commands ��

-2 ������ת 90 ��
-1 ������ת 90 ��
1 <= x <= 9 ����ǰ�ƶ� x ����λ����
����������һЩ���ӱ���Ϊ�ϰ��� obstacles ���� i ���ϰ���λ�������  obstacles[i] = (xi, yi) ��

�������޷��ߵ��ϰ����ϣ�������ͣ�����ϰ����ǰһ�����񷽿��ϣ�����Ȼ���Լ������Խ��и�·�ߵ����ಿ�֡�

���ش�ԭ�㵽���������о�����·���㣨����Ϊ�����������ŷʽ�����ƽ�����������������Ϊ 5 ���򷵻� 25 ��


ע�⣺

����ʾ +Y ����
����ʾ +X ����
�ϱ�ʾ -Y ����
����ʾ -X ����
*/
class Solution {
public:
	string get(int x, int y)
	{
		return to_string(x) + '#' + to_string(y);
	}

	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		unordered_set<string> s;
		for (auto& p : obstacles) s.insert(get(p[0], p[1]));
		int x = 0, y = 0, d = 0;
		int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
		int res = 0;
		for (auto c : commands)
		{
			if (c == -2) d = (d + 3) % 4;
			else if (c == -1) d = (d + 1) % 4;
			else
			{
				for (int i = 0; i < c; i++)
				{
					int a = x + dx[d], b = y + dy[d];
					if (s.count(get(a, b))) break;
					x = a, y = b;
					res = max(res, x * x + y * y);
				}
			}
		}
		return res;
	}
};