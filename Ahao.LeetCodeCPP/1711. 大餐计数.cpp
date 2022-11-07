#include<vector>
#include <unordered_map>

using namespace std;


/*
1711. 大餐计数
大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。

你可以搭配 任意 两道餐品做一顿大餐。

给你一个整数数组 deliciousness ，其中 deliciousness[i] 是第 i​​​​​​​​​​​​​​ 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 大餐 的数量。结果需要对 109 + 7 取余。

注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。
*/
class Solution {
public:
	int countPairs(vector<int>& deliciousness) {
		int res = 0, mod = 1e9 + 7;
		unordered_map<int, int> hash;
		for (auto x : deliciousness)
		{
			for (int i = 0; i <= 21; i++)
			{
				int t = (1 << i) - x;
				if (hash.count(t))
					res = (res + hash[t]) % mod;
			}
			hash[x]++;
		}
		return res;
	}
};

