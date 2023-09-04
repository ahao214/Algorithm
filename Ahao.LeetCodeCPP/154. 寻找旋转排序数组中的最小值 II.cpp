#include<vector>

using namespace std;

/*
154. Ѱ����ת���������е���Сֵ II

��֪һ������Ϊ n �����飬Ԥ�Ȱ����������У����� 1 �� n �� ��ת �󣬵õ��������顣���磬ԭ���� nums = [0,1,4,4,5,6,7] �ڱ仯����ܵõ���
����ת 4 �Σ�����Եõ� [4,5,6,7,0,1,4]
����ת 7 �Σ�����Եõ� [0,1,4,4,5,6,7]
ע�⣬���� [a[0], a[1], a[2], ..., a[n-1]] ��תһ�� �Ľ��Ϊ���� [a[n-1], a[0], a[1], a[2], ..., a[n-2]] ��

����һ�����ܴ��� �ظ� Ԫ��ֵ������ nums ����ԭ����һ���������е����飬�����������ν����˶����ת�������ҳ������������е� ��СԪ�� ��

����뾡���ܼ����������̵Ĳ������衣
*/


class Solution {
public:
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right && nums[right] == nums[0]) right--;
		if (nums[left] <= nums[right]) return nums[0];
		while (left < right)
		{
			int mid = left + right >> 1;
			if (nums[mid] < nums[0]) right = mid;
			else left = mid + 1;
		}
		return nums[right];
	}
};