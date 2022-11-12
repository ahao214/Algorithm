#include<vector>

using namespace std;


/*
2183. 统计可以被 K 整除的下标对数目
给你一个下标从 0 开始、长度为 n 的整数数组 nums 和一个整数 k ，返回满足下述条件的下标对 (i, j) 的数目：

0 <= i < j <= n - 1 且
nums[i] * nums[j] 能被 k 整除。
*/
vector<int> f[100001];
int flag = 0;

class Solution {
public:
	long long coutPairs(vector<int>& nums, int k) {
		if (flag == 0) {
			flag = 1;
			for (int i = 1; i < 100001; ++i) {
				for (int j = i; j < 100001; j += i) {
					f[j].emplace_back(i);
				}
			}
		}
		vector<long long> cnt(100001);
		long long ans = 0;
		for (auto x : nums) {
			int m = k / gcd(x, k);
			ans += cnt[m];
			for (auto y : f[x]) {
				cnt[y]++;
			}
		}
		return ans;
	}


public:
	int c[100001], f[100001];
	int gcd(int a, int b)
	{
		if (!b)
			return a;
		return gcd(b, a % b);
	}

	long long coutPairs(vector<int>& nums, int k) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			++c[nums[i]];
		}
		for (int i = 1; i <= 100000; i++)
		{
			for (int j = i; j <= 100000; j += i)
				f[i] += c[j];
		}
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += f[k / gcd(k, nums[i])];
			if (1ll * nums[i] * nums[i] % k == 0)
				ans--;
		}
		ans /= 2;
		return ans;
	}
};