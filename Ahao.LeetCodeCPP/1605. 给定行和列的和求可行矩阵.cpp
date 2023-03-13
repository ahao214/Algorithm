#include<vector>

using namespace std;


/*
1605. 给定行和列的和求可行矩阵

给你两个非负整数数组 rowSum 和 colSum ，其中 rowSum[i] 是二维矩阵中第 i 行元素的和， colSum[j] 是第 j 列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。

请找到大小为 rowSum.length x colSum.length 的任意 非负整数 矩阵，且该矩阵满足 rowSum 和 colSum 的要求。

请你返回任意一个满足题目要求的二维矩阵，题目保证存在 至少一个 可行矩阵。
*/
class Solution {
	/*
	k k k a
	k k k b
	k k k c
	x y z

	[a,b,c]表示行的和
	[x,y,z]表示列的和

	res为结果数组
	res[0][0] = min(x,a)
	res[0][1] = min(y,a - res[0][0])
	res[0][2] = a - res[0][0] - res[0][1] = min(z,a - res[0][0] - res[0][1])
	*/
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int m = rowSum.size();
		int n = colSum.size();
		auto res = vector<vector<int>>(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int v = min(rowSum[i], colSum[j]);
				res[i][j] = v;
				rowSum[i] -= v;
				colSum[j] -= v;
			}
		}
		return res;
	}
};



class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int n = rowSum.size(), m = colSum.size();
		vector<vector<int>> matrix(n, vector<int>(m, 0));
		int i = 0, j = 0;
		while (i < n && j < m) {
			int v = min(rowSum[i], colSum[j]);
			matrix[i][j] = v;
			rowSum[i] -= v;
			colSum[j] -= v;
			if (rowSum[i] == 0) {
				++i;
			}
			if (colSum[j] == 0) {
				++j;
			}
		}
		return matrix;
	}
};
