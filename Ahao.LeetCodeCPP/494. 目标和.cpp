#include<vector>

using namespace std;



/*
494. Ŀ���

����һ���������� nums ��һ������ target ��

�������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�� ���ʽ ��

���磬nums = [2, 1] �������� 2 ֮ǰ��� '+' ���� 1 ֮ǰ��� '-' ��Ȼ���������õ����ʽ "+2-1" ��
���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ��
*/
class Solution {
	int dp[25][2005];
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int n = nums.size();
		nums.insert(nums.begin(), 0);
		int offset = 1000;
		dp[0][0 + offset] = 1;

		for (int i = 1; i <= n; i++) {
			for (int s = -1000; s <= 1000; s++) {
				if (s - nums[i] >= -1000 && s - nums[i] <= 1000)
					dp[i][s + offset] += dp[i - 1][s - nums[i] + offset];
				if (s + nums[i] >= -1000 && s + nums[i] <= 1000)
					dp[i][s + offset] += dp[i - 1][s + nums[i] + offset];
			}
		}
		return dp[n][target + offset];
	}
};