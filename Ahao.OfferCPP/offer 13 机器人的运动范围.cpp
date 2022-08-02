#include<vector>

using namespace std; ]



/*
offer 13 机器人的运动范围
*/
class Solution {
public:
	int movingCount(int threshold, int rows, int cols) {
		vector<vector<int>> visited(rows, vector<int>(cols, 0));
		return dfs(0, 0, rows, cols, threshold, visited);
	}

	int dfs(int i, int j, int r, int c, int k, vector<vector<int>>& visited)
	{
		if (i >= r || j >= c || k < getDigitSum(i, j) || visited[i][j])
			return 0;
		visited[i][j] = 1;
		return 1 + dfs(i + 1, j, r, c, k, visited) + dfs(i, j + 1, r, c, k, visited);
	}

	int getDigitSum(int i, int j)
	{
		int sum = 0;
		while (i)
		{
			sum += i % 10;
			i /= 10;
		}
		while (j)
		{
			sum += j % 10;
			j /= 10;
		}
		return sum;
	}
};