#include<vector>
#include<algorithm>


using namespace std;




/*
1755. 最接近目标值的子序列和
给你一个整数数组 nums 和一个目标值 goal 。

你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal) 。

返回 abs(sum - goal) 可能的 最小值 。

注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
*/
const int N = 2000010;
int q[N];
class Solution {
public:

	int n, cnt, g, ans;
	void dfs1(vector<int>& nums, int u, int s)
	{
		if (u == (n + 1) / 2)
		{
			q[cnt++] = s;
			return;
		}
		dfs1(nums, u + 1, s);
		dfs1(nums, u + 1, s + nums[u]);
	}

	void dfs2(vector<int>& nums, int u, int s)
	{
		if (u == n)
		{
			int left = 0, right = cnt - 1;
			while (left < right)
			{
				int mid = left + right + 1 >> 1;
				if (q[mid] + s <= g) left = mid;
				else right = mid - 1;
			}
			ans = min(ans, abs(q[right] + s - g));
			if (right + 1 < cnt)
			{
				ans = min(ans, abs(q[right + 1] + s - g));
			}
			return;
		}
		dfs2(nums, u + 1, s);
		dfs2(nums, u + 1, s + nums[u]);
	}

	int minAbsDifference(vector<int>& nums, int goal) {
		n = nums.size(), cnt = 0, g = goal, ans = INT_MAX;
		dfs1(nums, 0, 0);
		sort(q, q + cnt);
		dfs2(nums, (n + 1) / 2, 0);
		return ans;
	}
};

