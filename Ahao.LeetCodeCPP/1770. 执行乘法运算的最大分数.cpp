#include<vector>

using namespace std;


/*
1770. ִ�г˷������������
�����������ȷֱ� n �� m ���������� nums �� multipliers ������ n >= m �������±� �� 1 ��ʼ ������

��ʼʱ����ķ���Ϊ 0 ������Ҫִ��ǡ�� m ���������ڵ� i ���������� 1 ��ʼ �������У���Ҫ��

ѡ������ nums ��ͷ������ĩβ�� ������ x ��
���� multipliers[i] * x �֣����ۼӵ���ķ����С�
�� x ������ nums ���Ƴ���
��ִ�� m �������󣬷��� ��� ������
*/
class Solution {
public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		int n = nums.size(), m = multipliers.size();
		if (n >= m * 2)
		{
			int x = m, y = n - m;
			while (y < n) nums[x++] = nums[y++];
			n = x;
		}

		vector<vector<int>> f(n + 2, vector<int>(n + 2));
		for (int len = n - m + 1; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1;
				f[i][j] = max(f[i + 1][j] + nums[i - 1] * multipliers[n - len], f[i][j - 1] + nums[j - 1] * multipliers[n - len]);
			}
		}
		return f[1][n];
	}
};
