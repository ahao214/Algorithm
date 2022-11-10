#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
1679. K 和数对的最大数目
给你一个整数数组 nums 和一个整数 k 。

每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。

返回你可以对数组执行的最大操作数。
*/
class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		unordered_map<int, int> hash;
		for (auto c : nums) hash[c]++;
		int res = 0;
		for (auto item : hash)
		{
			int x = item.first;
			int y = k - x;
			if (hash.count(x) && hash.count(y))
			{
				int cnt = min(hash[x], hash[y]);
				if (x == y) cnt /= 2;
				res += cnt;
				hash[x] -= cnt, hash[y] -= cnt;
			}
		}
		return res;
	}
};