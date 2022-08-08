#include<vector>


using namespace std;


/*
1886. 判断矩阵经轮转后是否一致
给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，如果能够使 mat 与 target 一致，返回 true ；否则，返回 false 。
*/
class Solution {
public:
	vector<vector<int>> rotate(vector<vector<int>> a)
	{
		auto b = a;
		int n = a.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0, k = n - 1; j < n; j++, k--)
				b[i][j] = a[k][i];
		}
		return b;
	}

	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		for (int i = 0; i < 4; i++)
		{
			mat = rotate(mat);
			if (mat == target)
				return true;
		}
		return false;
	}

};
