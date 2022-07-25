#include<vector>
#include<stack>

using namespace std;



class Solution {
	/*
	85. 最大矩形
	给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
	*/
public:
	/*
	Times:O(n*m)
	Space:O(n)
	*/

	int maxArea(vector<int>& heights)
	{
		stack<int> stk;
		int ans = 0;
		heights.push_back(-1);
		for (int i = 0; i < heights.size(); i++)
		{
			while (!stk.empty() && heights[i] < heights[stk.top()])
			{
				int idx = stk.top();
				stk.pop();
				int left = stk.empty() ? -1 : stk.top();
				ans = max(ans, (i - left - 1) * heights[idx]);
			}
			stk.push(i);
		}
		heights.pop_back();
		return ans;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<int> heights(n);
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
					heights[j]++;
				else
					heights[j] = 0;
			}
			ans = max(ans, maxArea(heights));
		}
		return ans;
	}
};
