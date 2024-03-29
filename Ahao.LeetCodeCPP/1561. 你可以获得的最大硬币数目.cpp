#include<vector>
#include <algorithm>

using namespace std;


/*
1561. 你可以获得的最大硬币数目
有 3n 堆数目不一的硬币，你和你的朋友们打算按以下方式分硬币：

每一轮中，你将会选出 任意 3 堆硬币（不一定连续）。
Alice 将会取走硬币数量最多的那一堆。
你将会取走硬币数量第二多的那一堆。
Bob 将会取走最后一堆。
重复这个过程，直到没有更多硬币。
给你一个整数数组 piles ，其中 piles[i] 是第 i 堆中硬币的数目。

返回你可以获得的最大硬币数目。
*/
class Solution {
public:
	int maxCoins(vector<int>& piles) {
		int res = 0;
		sort(piles.begin(), piles.end());
		for (int i = 0, j = piles.size() - 1; i < j; i++, j -= 2)
			res += piles[j - 1];
		return res;
	}
};

