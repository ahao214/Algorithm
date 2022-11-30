using namespace std;
#include<vector>
#include <algorithm>


/*
47. ȫ���� II
����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�
*/
class Solution {
	vector<vector<int>> ans;
	vector<int> combine;
	vector<bool> used;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		used = vector<bool>(nums.size());
		sort(nums.begin(), nums.end());

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
				if (i && nums[i - 1] == nums[i] && !used[i - 1]) continue;
				combine.push_back(nums[i]);
				used[i] = true;
				dfs(nums, idx + 1);
				used[i] = false;
				combine.pop_back();
			}
		}
	}
};
