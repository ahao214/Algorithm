#include<vector>

using namespace std;


/*
1365. �ж���С�ڵ�ǰ���ֵ�����
����һ������ nums����������ÿ��Ԫ�� nums[i]������ͳ�������б���С���������ֵ���Ŀ��

������֮������ÿ�� nums[i] �����������Ч�� j ������������ j ���� j != i �� nums[j] < nums[i] ��

��������ʽ���ش𰸡�
*/
class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> res(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			for (auto y : nums)
				if (y < nums[i])
					res[i]++;
		}
		return res;
	}
};
