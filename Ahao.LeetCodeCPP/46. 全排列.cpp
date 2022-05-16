using namespace std;
#include<vector>


class Solution {
	/*
	46. ȫ����
	����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
	*/
	vector<vector<int>> ans;
	vector<int> combine;
	vector<bool> used;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		used = vector<bool>(nums.size());
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int idx)
	{
		if (idx == nums.size())
		{
			ans.push_back(combine);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (!used[i])
			{
				combine.push_back(nums[i]);
				used[i] = true;
				dfs(nums, idx + 1);
				used[i] = false;
				combine.pop_back();
			}
		}
	}
};
