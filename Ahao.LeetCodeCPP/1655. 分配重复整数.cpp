#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
1655. 分配重复整数
给你一个长度为 n 的整数数组 nums ，这个数组中至多有 50 个不同的值。同时你有 m 个顾客的订单 quantity ，其中，整数 quantity[i] 是第 i 位顾客订单的数目。请你判断是否能将 nums 中的整数分配给这些顾客，且满足：

第 i 位顾客 恰好 有 quantity[i] 个整数。
第 i 位顾客拿到的整数都是 相同的 。
每位顾客都满足上述两个要求。
如果你可以分配 nums 中的整数满足上面的要求，那么请返回 true ，否则返回 false 。
*/
class Solution {
public:
	bool canDistribute(vector<int>& nums, vector<int>& quantity) {
		unordered_map<int, int> hash;
		for (auto x : nums) hash[x]++;
		vector<int> w(1);
		for (auto [x, y] : hash) w.push_back(y);
		int n = hash.size(), m = quantity.size();
		vector<int> s(1 << m);
		for (int i = 0; i < 1 << m; i++)
			for (int j = 0; j < m; j++)
				if (i >> j & 1)
					s[i] += quantity[j];

		vector<vector<int>> f(n + 1, vector<int>(1 << m));
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 1 << m; j++)
				if (f[i][j]) {
					f[i + 1][j] = 1;
					for (int t = j ^ ((1 << m) - 1), k = t; k; k = (k - 1) & t)
						if (s[k] <= w[i + 1])
							f[i + 1][j | k] = 1;
				}

		return f[n][(1 << m) - 1];
	}
};


