#include<vector>

using namespace std;


/*
162. Ѱ�ҷ�ֵ

��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء�

����һ���������� nums���ҵ���ֵԪ�ز�������������������ܰ��������ֵ������������£����� �κ�һ����ֵ ����λ�ü��ɡ�

����Լ��� nums[-1] = nums[n] = -�� ��

�����ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨����������⡣
*/
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1 || nums[0] > nums[1])
			return 0;
		int left = 1, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right + 1) >> 1;
			if (nums[mid] > nums[mid - 1])
			{
				left = mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		return right;
	}
};




class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + right >> 1;
			if (nums[mid] > nums[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}
		return right;
	}
};




class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}
		return right;
	}
};