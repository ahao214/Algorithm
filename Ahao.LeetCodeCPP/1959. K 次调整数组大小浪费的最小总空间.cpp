#include<vector>

using namespace std;



/*
1959. K �ε��������С�˷ѵ���С�ܿռ�
���������һ����̬���顣����һ���±�� 0 ��ʼ���������� nums ������ nums[i] �� i ʱ�������е�Ԫ����Ŀ���������⣬�㻹��һ������ k ����ʾ����� ���� �����С�� ��� ������ÿ�ζ����Ե����� ���� ��С����

t ʱ������Ĵ�С sizet ������ڵ��� nums[t] ����Ϊ������Ҫ���㹻�Ŀռ���������Ԫ�ء�t ʱ�� �˷ѵĿռ� Ϊ sizet - nums[t] ���� �˷ѿռ�Ϊ���� 0 <= t < nums.length ��ÿһ��ʱ�� t �˷ѵĿռ� ֮�� ��

�ڵ��������С������ k �ε�ǰ���£����㷵�� ��С���˷ѿռ� ��

ע�⣺�����ʼʱ����Ϊ �����С ���� ������ ������С�Ĳ���������
*/
class Solution {
public:
	int minSpaceWastedKResizing(vector<int>& nums, int k) {
		k++;
		int n = nums.size(), INF = 1e9;
		vector<vector<int>> f(n + 1, vector<int>(k + 1, INF));
		f[0][0] = 0;
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i && j <= k; j++)
			{
				for (int u = i, h = 0; u; u--)
				{
					h = max(h, nums[u - 1]);
					f[i][j] = min(f[i][j], f[u - 1][j - 1] + h * (i - u + 1) - (s[i] - s[u - 1]));
				}
			}
		}
		return f[n][k];
	}
};