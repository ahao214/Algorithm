#include<vector>
#include <algorithm>

using namespace std;


/*
1509. ���β��������ֵ����Сֵ����С��
����һ������ nums ��ÿ�β��������ѡ�� nums �е�����һ��Ԫ�ز������ĳ�����ֵ��

���㷵�����β����� nums �����ֵ����Сֵ�Ĳ����Сֵ��
*/
class Solution {
public:
	int minDifference(vector<int>& nums) {
		if (nums.size() <= 3) return 0;

		sort(nums.begin(), nums.end());
		int res = INT_MAX;
		for (int i = 0, j = 3; i <= 3; i++, j--)
		{
			res = min(res, nums[nums.size() - 1 - j] - nums[i]);
		}
		return res;
	}
};