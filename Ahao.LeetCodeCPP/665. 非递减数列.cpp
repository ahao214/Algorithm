#include<vector>

using namespace std;


/*
665. �ǵݼ�����

����һ������Ϊ n ���������� nums �������ж��� ��� �ı� 1 ��Ԫ�ص�����£��������ܷ���һ���ǵݼ����С�

��������������һ���ǵݼ����еģ� ��������������� i (0 <= i <= n-2)�������� nums[i] <= nums[i + 1]��
*/
class Solution {
public:
	bool check(vector<int>& nums)
	{
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - 1])
				return false;
		}
		return true;
	}

	bool checkPossibility(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - 1])
			{
				int a = nums[i - 1], b = nums[i];
				nums[i - 1] = nums[i] = a;
				if (check(nums)) return true;
				nums[i - 1] = nums[i] = b;
				if (check(nums)) return true;
				return false;
			}
		}
		return true;
	}
};
