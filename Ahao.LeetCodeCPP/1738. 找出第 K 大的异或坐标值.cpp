#include<vector>

using namespace std;


/*
1738. 找出第 K 大的异或坐标值
给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。

矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。

请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。
*/

const int N = 1000010;
int q[N];

class Solution {
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int n = matrix.size(), m = matrix[0].size();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i) matrix[i][j] ^= matrix[i - 1][j];
				if (j) matrix[i][j] ^= matrix[i][j - 1];
				if (i && j) matrix[i][j] ^= matrix[i - 1][j - 1];
				q[cnt++] = matrix[i][j];
			}
		}
		k = cnt - k;
		nth_element(q, q + k, q + cnt);
		return q[k];
	}
};