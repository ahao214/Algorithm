using namespace std;

#include<vector>


class Solution {
	/*
	53. ����������
	����һ���������� nums �������ҳ�һ���������͵�����������
	�����������ٰ���һ��Ԫ�أ������������͡�

	������ �������е�һ���������֡�
	*/
public:
	int maxSubArray(vector<int>& nums) {
		int pre = nums[0], ans = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			pre = pre > 0 ? pre + nums[i] : nums[i];
			ans = max(ans, pre);
		}
		return ans;
	}
};
