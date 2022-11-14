#include<vector>

using namespace std;


/*
1569. 将子数组重新排序得到同一个二叉查找树的方案数
给你一个数组 nums 表示 1 到 n 的一个排列。我们按照元素在 nums 中的顺序依次插入一个初始为空的二叉查找树（BST）。请你统计将 nums 重新排序后，统计满足如下条件的方案数：重排后得到的二叉查找树与 nums 原本数字顺序得到的二叉查找树相同。

比方说，给你 nums = [2,1,3]，我们得到一棵 2 为根，1 为左孩子，3 为右孩子的树。数组 [2,3,1] 也能得到相同的 BST，但 [3,2,1] 会得到一棵不同的 BST 。

请你返回重排 nums 后，与原数组 nums 得到相同二叉查找树的方案数。

由于答案可能会很大，请将结果对 10^9 + 7 取余数。
*/
typedef long long LL;
class Solution {
public:
	vector<vector<int>> C;
	const int MOD = 1e9 + 7;

	int numOfWays(vector<int>& nums) {
		int n = nums.size();
		C = vector<vector<int>>(n + 1, vector<int>(n + 1));
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (!j) C[i][j] = 1;
				else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			}
		}
		return (f(nums) + MOD - 1) % MOD;
	}

	int f(vector<int> nums)
	{
		if (nums.empty())
			return 1;
		int n = nums.size();
		int k = nums[0];
		vector<int> left, right;
		for (auto x : nums)
		{
			if (x < k) left.push_back(x);
			else if (x > k) right.push_back(x - k);
		}
		return (LL)C[n - 1][k - 1] * f(left) % MOD * f(right) % MOD;
	}
};