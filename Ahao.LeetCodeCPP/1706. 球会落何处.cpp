#include<vector>

using namespace std;


/*
1706. �����δ�
��һ����СΪ m x n �Ķ�ά���� grid ��ʾһ�����ӡ����� n �������ӵĶ����͵ײ����ǿ��ŵġ�

�����е�ÿ����Ԫ����һ���Խ��ߵ��壬�����Ԫ��������ǣ����Խ������������Ҳࡣ

�������Ҳ�ĵ��������ϽǺ����½ǣ����������� 1 ��ʾ��
���������ĵ��������ϽǺ����½ǣ����������� -1 ��ʾ��
������ÿһ�еĶ��˸���һ����ÿ���򶼿��ܿ����������ӵײ��������������ǡ�ÿ������鵲��֮��� "V" ��ͼ�������߱�һ�鵲�������ӵ�����һ����ϣ��ͻῨס��

����һ����СΪ n ������ answer ������ answer[i] ������ڶ����ĵ� i �к�ӵײ�����������һ�ж�Ӧ���±꣬������ں�����򷵻�
*/
class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<int> res;
		for (int i = 0; i < m; i++)
		{
			int x = 0, y = i, z = 0;
			while (x < n)
			{
				if (!z)
				{
					if (grid[x][y] == 1)
					{
						if (y + 1 >= m || grid[x][y + 1] == -1) y = -1;
						else y++, z = 1;
					}
					else {
						if (y - 1 < 0 || grid[x][y - 1] == 1) y = -1;
						else y--, z = 1;
					}
				}
				else {
					x++, z = 0;
				}
				if (y == -1) break;
			}
			res.push_back(y);
		}
		return res;
	}
};
