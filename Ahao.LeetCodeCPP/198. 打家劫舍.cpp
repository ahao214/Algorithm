#include<vector>

using namespace std;

/*
198. 打家劫舍
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int rob = nums[0], norob = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			int robTmp = rob, norobTmp = norob;
			norob = max(robTmp, norobTmp);
			rob = norobTmp + nums[i];
		}
		return max(rob, norob);
	}
};



/*
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一
制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，
计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		//f[i]表示在前i个数中选，所有不选nums[i]的选法的最大值
		//g[i]表示在前i个数中选，所有选择nums[i]的选法的最大值
		vector<int> f(n + 1), g(n + 1);
		for (int i = 1; i <= n; i++)
		{
			f[i] = max(f[i - 1], g[i - 1]);
			g[i] = nums[i - 1] + f[i - 1];
		}
		return max(f[n], g[n]);
	}
};