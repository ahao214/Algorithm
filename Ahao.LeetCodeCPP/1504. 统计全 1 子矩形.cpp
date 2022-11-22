#include<vector>
#include <stack>

using namespace std;



/*
1504. 统计全 1 子矩形
给你一个只包含 0 和 1 的 rows * columns 矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。
*/
class Solution {
public:
	int numSubmat(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		vector<vector<int>> f(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (mat[i][j])
				{
					f[i][j] = 1;
					if (i) f[i][j] += f[i - 1][j];
				}

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			stack<pair<int, int>> stk;
			for (int j = 0; j < m; j++)
			{
				while (stk.size() && f[i][stk.top().first] >= f[i][j])
				{
					stk.pop();
				}
				int s = 0;
				if (stk.size())
				{
					s += stk.top().second;
					s += (j - stk.top().first) * f[i][j];
				}
				else {
					s += (j + 1) * f[i][j];
				}
				stk.push({ j,s });
				res += s;
			}
		}
		return res;
	}
};

