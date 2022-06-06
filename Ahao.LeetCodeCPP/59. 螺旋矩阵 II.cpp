using namespace std;

#include<vector>


class Solution {
	/*
	59. 螺旋矩阵 II
	给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
	*/
public:
	/*
	Times:O(n^2)
	Space:O(1)
	*/
	vector<vector<int>> generateMatrix(int n) {
		int up = 0, down = n - 1, left = 0, right = n - 1;
		int num = 1;
		vector<vector<int>> ans(n, vector<int>(n));
		while (true)
		{
			//填充上边界
			for (int i = left; i <= right; i++) ans[up][i] = num++;
			if (++up > down) break;

			//填充右边界
			for (int i = up; i <= down; i++) ans[i][right] = num++;
			if (--right < left) break;

			//填充下边界
			for (int i = right; i >= left; i--) ans[down][i] = num++;
			if (--down < up) break;

			//填充左边界
			for (int i = down; i >= up; i--) ans[i][left] = num++;
			if (++left > right) break;

		}
		return ans;
	}
};