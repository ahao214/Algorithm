#include<vector>
#include <algorithm>

using namespace std;


/*
1492. n 的第 k 个因子
给你两个正整数 n 和 k 。

如果正整数 i 满足 n % i == 0 ，那么我们就说正整数 i 是整数 n 的因子。

考虑整数 n 的所有因子，将它们 升序排列 。请你返回第 k 个因子。如果 n 的因子数少于 k ，请你返回 -1 。
*/
class Solution {
public:
	int kthFactor(int n, int k) {
		vector<int> res;
		for (int i = 1; i <= n / i; i++)
		{
			if (n % i == 0)
			{
				res.push_back(i);
				if (n / i != i) res.push_back(n / i);
			}
		}
		sort(res.begin(), res.end());
		if (k > res.size()) return -1;
		return res[k - 1];
	}

	int kthFactor(int n, int k) {
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0 && --k == 0)
				return i;
		}
		return -1;
	}
};