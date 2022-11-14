#include<vector>

using namespace std;


/*
1477. ��������ΪĿ��ֵ�Ҳ��ص���������

����һ���������� arr ��һ������ֵ target ��

������ arr ���� ���������ص��������� �����ǵĺͶ����� target �����ܻ��ж��ַ��������㷵������Ҫ������������鳤�Ⱥ͵� ��Сֵ ��

�뷵������Ҫ�����С���Ⱥͣ�����޷��ҵ����������������飬�뷵�� -1 ��
*/
class Solution {
public:
	int minSumOfLengths(vector<int>& arr, int target) {
		int n = arr.size();
		vector<int> f(n, 1e8);

		int res = INT_MAX;
		for (int i = 0, j = 0, sum = 0; i < n; i++)
		{
			sum += arr[i];
			while (sum > target) sum -= arr[j++];
			if (sum == target)
			{
				if (j) res = min(res, i - j + 1 + f[j - 1]);
				f[i] = i - j + 1;
			}
			if (i) f[i] = min(f[i], f[i - 1]);
		}
		if (res > arr.size()) return -1;
		return res;
	}
};