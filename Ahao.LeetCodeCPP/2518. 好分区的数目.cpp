#include<vector>
#include <numeric>

using namespace std;




/*
2518. �÷�������Ŀ
����һ������������ nums ��һ������ k ��

���� �Ķ����ǣ������黮�ֳ���������� �� ��������ÿ��Ԫ�� ǡ�� ������ ĳһ�� ���С����������ÿ�����Ԫ�غͶ����ڵ��� k ������Ϊ������һ���÷�����

���� ��ͬ �ĺ÷�������Ŀ�����ڴ𰸿��ܴܺ��뷵�ض� 109 + 7 ȡ�� ��Ľ����

��������������У�����ĳ��Ԫ�� nums[i] �����ڲ�ͬ�����У�����Ϊ������������ͬ��
*/
using LL = long long;
LL MOD = 1e9 + 7;
class Solution {
	LL dp[1005][1005];
public:
	int countPartitions(vector<int>& nums, int k) {
		if (accumulate(nums.begin(), nums.end(), 0LL) < 2 * k)
			return 0;

		int n = nums.size();
		nums.insert(nums.begin(), 0);

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int s = 0; s < k; s++) {
				dp[i][s] += dp[i - 1][s];
				if (s >= nums[i]) {
					dp[i][s] += dp[i - 1][s - nums[i]];
				}
				dp[i][s] %= MOD;
			}
		}

		LL invalid = 0;
		for (int s = 0; s < k; s++) {
			invalid = (invalid + dp[n][s]) % MOD;
		}

		int total = 1;
		for (int i = 0; i < n; i++) {
			total = (total * 2) % MOD;
		}
		return (total - 2 * invalid + MOD) % MOD;
	}
};

