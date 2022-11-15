#include<vector>

using namespace std;


/*
2221. 数组的三角和

给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是 0 到 9 之间（两者都包含）的一个数字。

nums 的 三角和 是执行以下操作以后最后剩下元素的值：

nums 初始包含 n 个元素。如果 n == 1 ，终止 操作。否则，创建 一个新的下标从 0 开始的长度为 n - 1 的整数数组 newNums 。
对于满足 0 <= i < n - 1 的下标 i ，newNums[i] 赋值 为 (nums[i] + nums[i+1]) % 10 ，% 表示取余运算。
将 newNums 替换 数组 nums 。
从步骤 1 开始 重复 整个过程。
请你返回 nums 的三角和。
*/
using ll = long long;
class Solution {
public:
	int triangularSum(vector<int>& nums) {
		int n = nums.size() - 1;
		ll comb[1000][1000];
		for (int i = 0; i <= n; i++) {
			comb[i][i] = comb[i][0] = 1;
			if (i == 0)
				continue;
			for (int j = 1; j < i; ++j) {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
				comb[i][j] %= 10;
			}
		}
		ll res = 0;
		for (int i = 0; i <= n; i++) {
			res += nums[i] * comb[n][i] % 10;
		}
		return res % 10;
	}
};