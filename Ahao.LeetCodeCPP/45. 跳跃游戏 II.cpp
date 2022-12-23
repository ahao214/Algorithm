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


/*
45. ��Ծ��Ϸ II
����һ���Ǹ��������� nums �������λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

���������ǿ��Ե�����������һ��λ�á�
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int left = 0, right = 0, step = 0;
		while (left <= right) {
			int maxR = 0;
			for (int i = left; i <= right; i++)
				maxR = max(maxR, i + nums[i]);
			left = right + 1, right = maxR;
			step++;
			if (right >= (int)nums.size() - 1)
				break;
		}
		return step;
	}
};