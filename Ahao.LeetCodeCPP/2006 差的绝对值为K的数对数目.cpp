#include<vector>

using namespace std;


/*
2006. ��ľ���ֵΪ K ��������Ŀ
����һ���������� nums ��һ������ k �����㷵������ (i, j) ����Ŀ������ i < j �� |nums[i] - nums[j]| == k ��

|x| ��ֵ����Ϊ��

��� x >= 0 ����ôֵΪ x ��
��� x < 0 ����ôֵΪ -x ��
*/
class Solution {
public:
	int countKDifference(vector<int>& nums, int k) {
		int n = nums.size(), res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (abs(nums[i] - nums[j]) == k)
					res++;
			}
		}
		return res;
	}
};