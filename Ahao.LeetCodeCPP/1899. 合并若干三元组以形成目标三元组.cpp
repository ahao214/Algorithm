#include<vector>

using namespace std;


/*
1899. 合并若干三元组以形成目标三元组
三元组 是一个由三个整数组成的数组。给你一个二维整数数组 triplets ，其中 triplets[i] = [ai, bi, ci] 表示第 i 个 三元组 。同时，给你一个整数数组 target = [x, y, z] ，表示你想要得到的 三元组 。

为了得到 target ，你需要对 triplets 执行下面的操作 任意次（可能 零 次）：

选出两个下标（下标 从 0 开始 计数）i 和 j（i != j），并 更新 triplets[j] 为 [max(ai, aj), max(bi, bj), max(ci, cj)] 。
例如，triplets[i] = [2, 5, 3] 且 triplets[j] = [1, 7, 5]，triplets[j] 将会更新为 [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5] 。
如果通过以上操作我们可以使得目标 三元组 target 成为 triplets 的一个 元素 ，则返回 true ；否则，返回 false 。
*/
class Solution {
public:
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
		int x = 0, y = 0, z = 0;
		for (auto& t : triplets)
		{
			if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
			x = max(x, t[0]), y = max(y, t[1]), z = max(z, t[2]);
		}
		return x == target[0] && y == target[1] && z == target[2];
	}

};
