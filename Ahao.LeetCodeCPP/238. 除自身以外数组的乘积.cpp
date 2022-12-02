#include<vector>

using namespace std;


/*
238. ��������������ĳ˻�
����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��

��Ŀ���� ��֤ ���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����  32 λ ������Χ�ڡ�

�벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
*/
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size());
		for (int i = 0, t = 1; i < nums.size(); i++)
		{
			res[i] = t;
			t *= nums[i];
		}
		for (int i = nums.size() - 1, t = 1; i >= 0; i--)
		{
			res[i] *= t;
			t *= nums[i];
		}
		return res;
	}
};

