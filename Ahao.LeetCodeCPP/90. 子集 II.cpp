#include<vector>
#include <algorithm>

using namespace std;


/*
90. �Ӽ� II
����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����

�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�
*/
class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int u)
	{
		if (u == nums.size())
		{
			ans.push_back(path);
			return;
		}

		//���㵱ǰ���ֵĸ���
		int k = 0;
		while (u + k < nums.size() && nums[u + k] == nums[u]) k++;
		for (int i = 0; i <= k; i++)
		{
			dfs(nums, u + k);
			path.push_back(nums[u]);
		}

		//�ָ��ֳ�
		for (int i = 0; i <= k; i++)
			path.pop_back();
	}
};