using namespace std;
#include<vector>


class Solution {
	/*
	45. ��Ծ��Ϸ II
	����һ���Ǹ��������� nums �������λ������ĵ�һ��λ�á�

	�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

	���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

	���������ǿ��Ե�����������һ��λ�á�
	*/
public:
	int jump(vector<int>& nums) {
		int maxPos = 0, end = 0;
		int res = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			maxPos = max(maxPos, nums[i] + i);
			if (i == end)
			{
				end = maxPos;
				res++;
			}
		}
		return res;
	}
};

