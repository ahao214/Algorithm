#include<vector>

using namespace std;


/*
268. ��ʧ������
����һ������ [0, n] �� n ���������� nums ���ҳ� [0, n] �����Χ��û�г����������е��Ǹ�����
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (auto x : nums) sum += x;
		return nums.size() * (nums.size() + 1) / 2 - sum;
	}
};