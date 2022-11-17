#include<vector>

using namespace std;


/*
1562. 查找大小为 M 的最新分组
给你一个数组 arr ，该数组表示一个从 1 到 n 的数字排列。有一个长度为 n 的二进制字符串，该字符串上的所有位最初都设置为 0 。

在从 1 到 n 的每个步骤 i 中（假设二进制字符串和 arr 都是从 1 开始索引的情况下），二进制字符串上位于位置 arr[i] 的位将会设为 1 。

给你一个整数 m ，请你找出二进制字符串上存在长度为 m 的一组 1 的最后步骤。一组 1 是一个连续的、由 1 组成的子串，且左右两边不再有可以延伸的 1 。

返回存在长度 恰好 为 m 的 一组 1  的最后步骤。如果不存在这样的步骤，请返回 -1 。
*/
class Solution {
public:
	vector<int> left, right;
	int get(int x) {
		return right[x] - x + 1;
	}
	int findLatestStep(vector<int>& arr, int m) {
		int n = arr.size();
		left.resize(n + 2), right.resize(n + 2);
		int cnt = 0, res = -1;
		for (int i = 0; i < arr.size(); i++)
		{
			int x = arr[i];
			if (left[x - 1] && right[x + 1]) {
				if (get(left[x - 1]) == m) cnt--;
				if (get(x + 1) == m) cnt--;
				right[left[x - 1]] = right[x + 1];
				left[right[x + 1]] = left[x - 1];
				if (get(left[x - 1]) == m) cnt++;
			}
			else if (left[x - 1]) {
				if (get(left[x - 1]) == m) cnt--;
				right[left[x - 1]] = x, left[x] = left[x - 1];
				if (get(left[x - 1]) == m) cnt++;
			}
			else if (right[x + 1]) {
				if (get(x + 1) == m) cnt--;
				right[x] = right[x + 1];
				left[right[x + 1]] = x;
				if (get(x) == m) cnt++;
			}
			else {
				left[x] = right[x] = x;
				if (m == 1) cnt++;
			}
			if (cnt) res = i + 1;
		}
		return res;
	}
};

