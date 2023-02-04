#include<vector>
#include<algorithm>

using namespace std;




/*
1798. 你能构造出连续值的最大数目

给你一个长度为 n 的整数数组 coins ，它代表你拥有的 n 个硬币。第 i 个硬币的值为 coins[i] 。如果你从这些硬币中选出一部分硬币，它们的和为 x ，那么称，你可以 构造 出 x 。

请返回从 0 开始（包括 0 ），你最多能 构造 出多少个连续整数。

你可能有多个相同值的硬币。
*/
class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		sort(coins.begin(), coins.end());
		int sum = 0;
		for (auto x : coins)
		{
			if (x > sum + 1)
				return sum + 1;
			sum += x;
		}
		return sum + 1;
	}
};



//贪心
class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		int res = 1;
		sort(coins.begin(), coins.end());
		for (auto& i : coins) {
			if (i > res) {
				break;
			}
			res += i;
		}
		return res;
	}
};
