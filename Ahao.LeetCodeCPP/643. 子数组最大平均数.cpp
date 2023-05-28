#include<vector>
#include <numeric>

using namespace std;


/*
643. ���������ƽ���� I

����һ���� n ��Ԫ����ɵ��������� nums ��һ������ k ��

�����ҳ�ƽ��������� ����Ϊ k �����������飬����������ƽ������

�κ����С�� 10-5 �Ĵ𰸶�������Ϊ��ȷ�𰸡�
*/


class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double sum = accumulate(nums.begin(), nums.begin() + k, 0);
		double res = sum;
		for (int end = k; end < nums.size(); end++)
		{
			sum += nums[end] - nums[end - k];
			res = max(res, sum);
		}
		return res / k;
	}
};


class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double res = -1e5;
		for (int i = 0, j = 0, s = 0; i < nums.size(); i++)
		{
			s += nums[i];
			if (i - j + 1 > k) s -= nums[j++];
			if (i >= k - 1)
			{
				res = max(res, s / (double)k);
			}
		}
		return res;
	}
};

