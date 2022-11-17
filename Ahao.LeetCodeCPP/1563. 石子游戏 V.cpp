#include<vector>

using namespace std;


/*
1563. ʯ����Ϸ V
����ʯ�� �ų�һ�� ��ÿ��ʯ�Ӷ���һ������ֵ������ֵΪ������������ stoneValue ������

��Ϸ�е�ÿһ�֣�Alice �Ὣ����ʯ�ӷֳ����� �ǿ��У���������к��Ҳ��У���Bob �������ÿһ�е�ֵ��������������ʯ�ӵ�ֵ���ܺ͡�Bob �ᶪ��ֵ�����У�Alice �ĵ÷�Ϊʣ�����е�ֵ��ÿ���ۼӣ���������е�ֵ��ȣ�Bob �� Alice ����������һ�С���һ�ִ�ʣ�µ���һ�п�ʼ��

ֻ ʣ��һ��ʯ�� ʱ����Ϸ������Alice �ķ������Ϊ 0 ��

���� Alice �ܹ���õ������� ��
*/
class Solution {
public:
	vector<int> s;
	int get(int left, int right)
	{
		return s[right] - s[left - 1];
	}

	int stoneGameV(vector<int>& stoneValue) {
		int n = stoneValue.size();
		s.resize(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + stoneValue[i - 1];

		vector<vector<int>> f(n + 1, vector<int>(n + 1));
		for (int len = 2; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1, sum = get(i, j), k = i, p = stoneValue[i - 1];
				int t = 0;
				while (p < sum - p)
				{
					if (t < p + f[i][k]) t = p + f[i][k];
					p += stoneValue[k++];
				}
				if (p == sum - p)
				{
					if (t < p + max(f[i][k], f[k + 1][j]))
						t = p + max(f[i][k], f[k + 1][j]);
					p += stoneValue[k++];
				}
				while (k < j)
				{
					if (t < sum - p + f[k + 1][j])
						t = sum - p + f[k + 1][j];
					p += stoneValue[k++];
				}
				f[i][j] = t;
			}
		}
		return f[1][n];
	}
};
