#include<vector>

using namespace std;





/*
1906. 查询差绝对值的最小值
一个数组 a 的 差绝对值的最小值 定义为：0 <= i < j < a.length 且 a[i] != a[j] 的 |a[i] - a[j]| 的 最小值。如果 a 中所有元素都 相同 ，那么差绝对值的最小值为 -1 。

比方说，数组 [5,2,3,7,2] 差绝对值的最小值是 |2 - 3| = 1 。注意答案不为 0 ，因为 a[i] 和 a[j] 必须不相等。
给你一个整数数组 nums 和查询数组 queries ，其中 queries[i] = [li, ri] 。对于每个查询 i ，计算 子数组 nums[li...ri] 中 差绝对值的最小值 ，子数组 nums[li...ri] 包含 nums 数组（下标从 0 开始）中下标在 li 和 ri 之间的所有元素（包含 li 和 ri 在内）。

请你返回 ans 数组，其中 ans[i] 是第 i 个查询的答案。

子数组 是一个数组中连续的一段元素。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
*/


const int N = 100010, M = 110;
int s[N][M];

class Solution {
public:
	vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size(), m = queries.size();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 100; j++)
			{
				int t = 0;
				if (nums[i - 1] == j) t = 1;
				s[i][j] = s[i - 1][j] + t;
			}
		}

		vector<int> res(m);
		for (int i = 0; i < m; i++)
		{
			int left = queries[i][0] + 1, right = queries[i][1] + 1;
			int t = M, last = -1;
			for (int j = 1; j <= 100; j++)
			{
				if (s[right][j] > s[left - 1][j])
				{
					if (last != -1) t = min(t, j - last);
					last = j;
				}
			}
			if (t == M) t = -1;
			res[i] = t;
		}
		return res;
	}
};
