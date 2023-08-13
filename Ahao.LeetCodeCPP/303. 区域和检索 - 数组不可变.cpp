#include<vector>

using namespace std;



/*
303. ����ͼ��� - ���鲻�ɱ�

����һ����������  nums�������������͵Ķ����ѯ:

�������� left �� right ������ left �� right��֮��� nums Ԫ�ص� �� ������ left <= right
ʵ�� NumArray �ࣺ

NumArray(int[] nums) ʹ������ nums ��ʼ������
int sumRange(int i, int j) �������� nums ������ left �� right ֮���Ԫ�ص� �ܺ� ������ left �� right ���㣨Ҳ���� nums[left] + nums[left + 1] + ... + nums[right] )
*/
class NumArray {
public:
	vector<int> s;
	NumArray(vector<int>& nums) {
		s.resize(nums.size() + 1);
		for (int i = 1; i <= nums.size(); i++)
			s[i] = s[i - 1] + nums[i - 1];
	}

	int sumRange(int left, int right) {
		++left, ++right;
		return s[right] - s[left - 1];
	}
};