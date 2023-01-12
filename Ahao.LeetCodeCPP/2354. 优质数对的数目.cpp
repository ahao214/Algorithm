#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;



/*
2354. 优质数对的数目
给你一个下标从 0 开始的正整数数组 nums 和一个正整数 k 。

如果满足下述条件，则数对 (num1, num2) 是 优质数对 ：

num1 和 num2 都 在数组 nums 中存在。
num1 OR num2 和 num1 AND num2 的二进制表示中值为 1 的位数之和大于等于 k ，其中 OR 是按位 或 操作，而 AND 是按位 与 操作。
返回 不同 优质数对的数目。

如果 a != c 或者 b != d ，则认为 (a, b) 和 (c, d) 是不同的两个数对。例如，(1, 2) 和 (2, 1) 不同。

注意：如果 num1 在数组中至少出现 一次 ，则满足 num1 == num2 的数对 (num1, num2) 也可以是优质数对。
*/
class Solution {
public:
	long long countExcellentPairs(vector<int>& nums, int k) {
		unordered_set<int>st(nums.begin(), nums.end());

		vector<int> bits;
		for (auto x : st) {
			bits.push_back(__builtin_popcount(x));
		}

		sort(bits.begin(), bits.end());
		int n = bits.size();
		int j = n - 1;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			while (j >= 0 && bits[i] + bits[j] >= k) {
				j--;
			}
			if (j >= i)
				res += n - (j + 1);
			else
				res += n - (i + 1);
		}
		res *= 2;
		for (auto x : bits) {
			if (x * 2 >= k) {
				res += 1;
			}
		}
		return res;
	}
};

