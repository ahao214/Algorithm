#include<vector>

using namespace std;





/*
	1861. 旋转盒子
	给你一个 m x n 的字符矩阵 box ，它表示一个箱子的侧视图。箱子的每一个格子可能为：

	'#' 表示石头
	'*' 表示固定的障碍物
	'.' 表示空位置
	这个箱子被 顺时针旋转 90 度 ，由于重力原因，部分石头的位置会发生改变。每个石头会垂直掉落，直到它遇到障碍物，另一个石头或者箱子的底部。重力 不会 影响障碍物的位置，同时箱子旋转不会产生惯性 ，也就是说石头的水平位置不会发生改变。

	题目保证初始时 box 中的石头要么在一个障碍物上，要么在另一个石头上，要么在箱子的底部。

	请你返回一个 n x m的矩阵，表示按照上述旋转后，箱子内的结果。
	*/
class Solution {
public:
	vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		int n = box.size(), m = box[0].size();
		vector<vector<char>> res(m, vector<char>(n));
		//旋转90度
		for (int i = n - 1, k = 0; i >= 0; i--, k++)
		{
			for (int j = 0; j < m; j++)
			{
				res[j][k] = box[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1, k = m; j >= 0; j--)
			{
				if (res[j][i] == '*')
					k = j;
				else if (res[j][i] == '#')
				{
					res[j][i] = '.';
					res[--k][i] = '#';
				}
			}
		}
		return res;
	}

};
