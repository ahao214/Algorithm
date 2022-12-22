using namespace std;
#include<vector>

class Solution {
	/*
	54. 螺旋矩阵
	给你一个 m 行 n 列的矩阵 matrix ，
	请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
	*/
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		//上下左右的边界
		int up = 0, down = m - 1, left = 0, right = n - 1;
		vector<int> ans;
		while (true)
		{
			//上边界
			for (int i = left; i <= right; i++) ans.push_back(matrix[up][i]);
			if (++up > down) break;

			//右边界
			for (int i = up; i <= down; i++) ans.push_back(matrix[i][right]);
			if (--right < left) break;

			//下边界
			for (int i = right; i >= left; i--) ans.push_back(matrix[down][i]);
			if (--down < up) break;

			//左边界
			for (int i = down; i >= up; i--) ans.push_back(matrix[i][left]);
			if (++left > right) break;
		}
		return ans;
	}
};




/*
54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty()) return res;
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m));

		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

		int x = 0, y = 0, d = 1;
		for (int k = 0; k < n * m; k++)
		{
			res.push_back(matrix[x][y]);
			visited[x][y] = true;
			int a = x + dx[d], b = y + dy[d];
			if (a < 0 || a >= n || b < 0 || b >= m || visited[a][b])
			{
				d = (d + 1) % 4;
				a = x + dx[d], b = y + dy[d];
			}
			x = a, y = b;
		}
		return res;
	}
};