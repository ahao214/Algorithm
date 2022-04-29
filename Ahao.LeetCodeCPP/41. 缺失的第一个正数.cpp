using namespace std;
#include<vector>

class Solution {
	/*
	41. ȱʧ�ĵ�һ������
	����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������

	����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
	*/
public:
	int firstMissingPositive(vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (nums[i] != i + 1)
			{
				return i + 1;
			}
		}
		return n + 1;
	}
};
