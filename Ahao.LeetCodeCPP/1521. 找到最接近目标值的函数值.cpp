#include<vector>

using namespace std;


/*
1521. �ҵ���ӽ�Ŀ��ֵ�ĺ���ֵ

Winston ������һ��������ʾ�ĺ��� func ������һ���������� arr ��һ������ target �������ҵ��� |func(arr, l, r) - target| ��С�� l �� r ��

���㷵�� |func(arr, l, r) - target| ����Сֵ��

��ע�⣬ func ��������� l �� r ��Ҫ���� 0 <= l, r < arr.length ��
*/
class Solution {
public:
	vector<vector<int>> s;

	int getSum(int left, int right)
	{
		int res = 0;
		for (int i = 0; i < 20; i++)
		{
			if (s[i][right] - s[i][left - 1] == 0)
				res += 1 << i;
		}
		return res;
	}
	int closestToTarget(vector<int>& arr, int target) {
		int n = arr.size();
		s = vector<vector<int>>(20, vector<int>(n + 1));
		for (int i = 0; i < 20; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				s[i][j] = s[i][j - 1];
				if (!(arr[j - 1] >> i & 1)) s[i][j]++;
			}
		}

		int res = INT_MAX;
		for (int i = 1, j = 1; i <= n; i++)
		{
			while (j + 1 <= i && getSum(j + 1, i) <= target) j++;
			res = min(res, abs(getSum(j, i) - target));
			if (j < i)
				res = min(res, abs(getSum(j + 1, i) - target));
		}

		return res;
	}
};
