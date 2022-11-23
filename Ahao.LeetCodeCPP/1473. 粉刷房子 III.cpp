#include<vector>

using namespace std;


/*
1473. ��ˢ���� III
��һ��С������� m �������ų�һ�ţ�����Ҫ��ÿ������Ϳ�� n ����ɫ֮һ����ɫ���Ϊ 1 �� n �����еķ���ȥ�������Ѿ�Ϳ����ɫ�ˣ�������Щ���Ӳ����Ա�����Ϳɫ��

���ǽ�������ͬ��ɫ�����ܶ�ķ��ӳ�Ϊһ�����������ȷ�˵ houses = [1,2,2,3,3,2,1,1] �������� 5 ������  [{1}, {2,2}, {3,3}, {2}, {1,1}] ����

����һ������ houses ��һ�� m * n �ľ��� cost ��һ������ target �����У�

houses[i]���ǵ� i �����ӵ���ɫ��0 ��ʾ������ӻ�û�б�Ϳɫ��
cost[i][j]���ǽ��� i ������Ϳ����ɫ j+1 �Ļ��ѡ�
���㷵�ط���Ϳɫ��������С�ܻ��ѣ�ʹ��ÿ�����Ӷ���Ϳɫ��ǡ����� target �����������û�п��õ�Ϳɫ�������뷵�� -1 ��
*/
class Solution {
public:
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		const int INF = 1e8;
		vector<vector<vector<int>>> f(m, vector<vector<int>>(m + 1, vector<int>(n + 1, INF)));

		if (houses[0]) f[0][1][houses[0]] = 0;
		else
		{
			for (int i = 1; i <= n; i++)
			{
				f[0][1][i] = cost[0][i - 1];
			}
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j <= target; j++)
			{
				if (houses[i])
				{
					int k = houses[i];
					for (int u = 1; u <= n; u++)
					{
						if (u == k)
							f[i][j][k] = min(f[i][j][k], f[i - 1][j][u]);
						else
							f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][u]);
					}
				}
				else {
					for (int k = 1; k <= n; k++)
					{
						for (int u = 1; u <= n; u++)
						{
							if (u == k)
								f[i][j][k] = min(f[i][j][k], f[i - 1][j][u] + cost[i][k - 1]);
							else
								f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][u] + cost[i][k - 1]);
						}
					}
				}
			}
		}
		int res = INF;
		for (int i = 1; i <= n; i++)
		{
			res = min(res, f[m - 1][target][i]);
		}
		if (res == INF)
			res = -1;
		return res;
	}
};