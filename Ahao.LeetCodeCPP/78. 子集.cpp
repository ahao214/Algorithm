#include<vector>

using namespace std;

class Solution {
	/*
	78. �Ӽ�
	����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����

	�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
	*/
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		for (int mask = 0; mask < (1 << n); mask++)
		{
			vector<int> subset;
			for (int i = 0; i < n; i++)
			{
				if (mask & (1 << i)) subset.push_back(nums[i]);
			}
			ans.push_back(subset);
		}
		return ans;
	}
};
