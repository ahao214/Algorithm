#include<vector>
#include <algorithm>

using namespace std;


/*
1478. ������Ͳ
����һ����������houses ��һ������ k ������ houses[i] �ǵ� i ��������һ�����ϵ�λ�ã�����Ҫ���������ϰ��� k ����Ͳ��

���㷵��ÿ�������������������Ͳ֮��ľ���� ��С �ܺ͡�

�𰸱�֤�� 32 λ�з���������Χ���ڡ�
*/
class Solution {
public:
	int minDistance(vector<int>& houses, int k) {
		sort(houses.begin(), houses.end());
		int n = houses.size();
		vector<vector<int>> f(n, vector<int>(k + 1));
		vector<vector<int>> cost(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				for (int r = i; r <= j; r++)
					cost[i][j] += abs(houses[r] - houses[i + (j - i + 1) / 2]);

		for (int i = 0; i < n; i++) f[i][0] = 1e8;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				f[i][j] = 1e8;
				for (int r = 0; r <= i; r++)
				{
					int t = 0;
					if (r) t = f[r - 1][j - 1];
					f[i][j] = min(f[i][j], t + cost[r][i]);
				}
			}
		}

		return f[n - 1][k];
	}
};