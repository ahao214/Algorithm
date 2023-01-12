#include<vector>

using namespace std;



/*
2498. 青蛙过河 II
给你一个下标从 0 开始的整数数组 stones ，数组中的元素 严格递增 ，表示一条河中石头的位置。

一只青蛙一开始在第一块石头上，它想到达最后一块石头，然后回到第一块石头。同时每块石头 至多 到达 一次。

一次跳跃的 长度 是青蛙跳跃前和跳跃后所在两块石头之间的距离。

更正式的，如果青蛙从 stones[i] 跳到 stones[j] ，跳跃的长度为 |stones[i] - stones[j]| 。
一条路径的 代价 是这条路径里的 最大跳跃长度 。

请你返回这只青蛙的 最小代价 。
*/
class Solution {
public:
	int maxJump(vector<int>& stones) {
		int n = stones.size();
		int res = stones[1] - stones[0];
		for (int i = 2; i < n; i++) {
			res = max(res, stones[i] - stones[i - 2]);
		}
		return res;
	}
};
