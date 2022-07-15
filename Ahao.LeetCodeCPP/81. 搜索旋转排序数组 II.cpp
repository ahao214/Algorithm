#include<vector>

using namespace std;


class Solution {
	/*
	81. ������ת�������� II
	��֪����һ�����ǽ������е��������� nums �������е�ֵ���ػ�����ͬ��

	�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת ��ʹ�����Ϊ [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]���±� �� 0 ��ʼ �����������磬 [0,1,2,4,4,4,5,6,6,7] ���±� 5 ������ת����ܱ�Ϊ [4,5,6,6,7,0,1,2,4,4] ��

	���� ��ת�� ������ nums ��һ������ target �������дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С���� nums �д������Ŀ��ֵ target ���򷵻� true �����򷵻� false ��

	����뾡���ܼ��������������衣
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right && nums[left] == nums[right])
			right--;
		while (left < right)
		{
			int mid = left + (right - left) / 2 + 1;
			if (nums[mid] >= nums[0])
				left = mid;
			else
				right = mid - 1;
		}
		if (target >= nums[0])
			left = 0;
		else
			left = right + 1, right = nums.size() - 1;

		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		return nums[right] == target;
	}
};
