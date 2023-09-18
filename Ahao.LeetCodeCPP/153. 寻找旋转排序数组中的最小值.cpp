#include<vector>

using namespace std;



/*
153. Ѱ����ת���������е���Сֵ

��֪һ������Ϊ n �����飬Ԥ�Ȱ����������У����� 1 �� n �� ��ת �󣬵õ��������顣���磬ԭ���� nums = [0,1,2,4,5,6,7] �ڱ仯����ܵõ���
����ת 4 �Σ�����Եõ� [4,5,6,7,0,1,2]
����ת 7 �Σ�����Եõ� [0,1,2,4,5,6,7]
ע�⣬���� [a[0], a[1], a[2], ..., a[n-1]]��תһ�εĽ��Ϊ���� [a[n-1], a[0], a[1], a[2], ..., a[n-2]] ��

����һ��Ԫ��ֵ������ͬ������nums ����ԭ����һ���������е����飬�����������ν����˶����ת�������ҳ������������е���СԪ�� ��
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums[0] < nums.back()) return nums[0];
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (nums[mid] >= nums[0])
				l = mid + 1;
			else
				r = mid;
		}
		return nums[r];
	}
};



class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums[0] < nums.back()) return nums[0];
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (nums[mid] >= nums[0])
				l = mid + 1;
			else
				r = mid;
		}
		return nums[r];
	}
};




class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] <= nums.back())
				right = mid;
			else
				left = mid + 1;
		}
		return nums[right];
	}
};