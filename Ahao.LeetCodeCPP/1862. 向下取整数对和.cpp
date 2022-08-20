#include<vector>

using namespace std;



/*
1862. 向下取整数对和
给你一个整数数组 nums ，请你返回所有下标对 0 <= i, j < nums.length 的 floor(nums[i] / nums[j]) 结果之和。由于答案可能会很大，请你返回答案对109 + 7 取余 的结果。

函数 floor() 返回输入数字的整数部分。
*/

typedef long long LL;
const int N = 100010, MOD = 1e9 + 7;
int s[N];

class Solution {
public:
	int sumOfFlooredPairs(vector<int>& nums) {
		memset(s, 0, sizeof s);
		for (auto x : nums) s[x]++;
		for (int i = 1; i < N; i++) s[i] += s[i - 1];
		int res = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j * i < N; j++)
			{
				int left = j * i, right = min(N - 1, (j + 1) * i - 1);
				int sum = (LL)(s[right] - s[left - 1]) * j % MOD;
				res = (res + (LL)sum * (s[i] - s[i - 1])) % MOD;
			}
		}
		return res;
	}
};