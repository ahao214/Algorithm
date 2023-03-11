#include <algorithm>
using namespace std;


/*
668. 乘法表中第k小的数

几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第 k 小的数字吗？

乘法表是大小为 m x n 的一个整数矩阵，其中 mat[i][j] == i * j（下标从 1 开始）。

给你三个整数 m、n 和 k，请你在大小为 m x n 的乘法表中，找出并返回第 k 小的数字。
*/


class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right) {
			int x = left + (right - left) / 2;
			int count = x / n * n;
			for (int i = x / n + 1; i <= m; ++i) {
				count += x / i;
			}
			if (count >= k) {
				right = x;
			}
			else {
				left = x + 1;
			}
		}
		return left;
	}
};





class Solution {
public:
	int get(int m, int n, int mid)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
			res += min(m, mid / i);
		return res;
	}
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (get(m, n, mid) >= k) right = mid;
			else left = mid + 1;
		}
		return right;
	}
};