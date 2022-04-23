using namespace std;
#include<vector>

class Solution {
	/*
	33. ������ת��������
	�������� nums ���������У������е�ֵ ������ͬ ��

	�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length��
	�Ͻ����� ��ת��ʹ�����Ϊ [nums[k], nums[k+1], ..., nums[n-1], nums[0],
	nums[1], ..., nums[k-1]]���±� �� 0 ��ʼ ��������
	���磬 [0,1,2,4,5,6,7] ���±� 3 ������ת����ܱ�Ϊ [4,5,6,7,0,1,2] ��

	���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ
	target ���򷵻������±꣬���򷵻� -1 ��
	*/
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2 + 1;
			if (nums[mid] >= nums[0])
				l = mid;
			else
				r = mid - 1;
		}
		if (target >= nums[0])
			l = 0;
		else
			l = l + 1, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2 + 1;
			if (nums[mid] <= target)
				l = mid;
			else
				r = mid - 1;
		}
		return nums[r] == target ? r : -1;
	}
};