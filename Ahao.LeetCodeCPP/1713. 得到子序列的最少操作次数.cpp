#include<vector>
#include <unordered_map>

using namespace std;


/*
1713. 得到子序列的最少操作次数
给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。

每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr = [1,4,1,2] ，那么你可以在中间添加 3 得到 [1,4,3,1,2] 。你可以在数组最开始或最后面添加整数。

请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。

一个数组的 子序列 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的子序列（加粗元素），但 [2,4,2] 不是子序列。
*/
class Solution {
public:
	int minOperations(vector<int>& target, vector<int>& arr) {
		unordered_map<int, int> pos;
		for (int i = 0; i < target.size(); i++)
		{
			pos[target[i]] = i;
		}
		vector<int> a;
		for (auto x : arr)
			if (pos.count(x))
				a.push_back(pos[x]);

		int len = 0;
		vector<int> q(a.size() + 1);
		for (int i = 0; i < a.size(); i++)
		{
			int left = 0, right = len;
			while (left < right) {
				int mid = left + right + 1 >> 1;
				if (q[mid] < a[i]) left = mid;
				else right = mid - 1;
			}
			len = max(len, right + 1);
			q[right + 1] = a[i];
		}
		return target.size() - len;
	}
};