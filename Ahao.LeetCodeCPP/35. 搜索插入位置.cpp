using namespace std;
#include<vector>


/*
35. ��������λ��
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return r;
	}
};



/*
35. ��������λ��
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty() || nums.back() < target) return nums.size();
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + right >> 1;
			if (nums[mid] >= target)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return right;
	}
};