using namespace std;

#include<vector>


/*
53. ����������
����һ���������� nums �������ҳ�һ���������͵�����������
�����������ٰ���һ��Ԫ�أ������������͡�

������ �������е�һ���������֡�
*/
class Solution {
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




/*
53. ����������
����һ���������� nums �����ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ���
���������͡�

������ �������е�һ���������֡�
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0], sum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			sum = max(0, sum);
			sum += nums[i];
			res = max(res, sum);
		}
		return res;
	}
};