#include<vector>

using namespace std;


/*
1480. һά����Ķ�̬��
����һ������ nums �����顸��̬�͡��ļ��㹫ʽΪ��runningSum[i] = sum(nums[0]��nums[i]) ��

�뷵�� nums �Ķ�̬�͡�
*/
class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		vector<int> res(nums.size());
		res[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			res[i] = res[i - 1] + nums[i];
		}
		return res;
	}
};
