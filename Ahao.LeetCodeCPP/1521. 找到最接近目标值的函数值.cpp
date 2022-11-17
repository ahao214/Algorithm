#include<vector>

using namespace std;


/*
1521. 找到最接近目标值的函数值

Winston 构造了一个如上所示的函数 func 。他有一个整数数组 arr 和一个整数 target ，他想找到让 |func(arr, l, r) - target| 最小的 l 和 r 。

请你返回 |func(arr, l, r) - target| 的最小值。

请注意， func 的输入参数 l 和 r 需要满足 0 <= l, r < arr.length 。
*/
class Solution {
public:
	vector<vector<int>> s;

	int getSum(int left, int right)
	{
		int res = 0;
		for (int i = 0; i < 20; i++)
		{
			if (s[i][right] - s[i][left - 1] == 0)
				res += 1 << i;
		}
		return res;
	}
	int closestToTarget(vector<int>& arr, int target) {
		int n = arr.size();
		s = vector<vector<int>>(20, vector<int>(n + 1));
		for (int i = 0; i < 20; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				s[i][j] = s[i][j - 1];
				if (!(arr[j - 1] >> i & 1)) s[i][j]++;
			}
		}

		int res = INT_MAX;
		for (int i = 1, j = 1; i <= n; i++)
		{
			while (j + 1 <= i && getSum(j + 1, i) <= target) j++;
			res = min(res, abs(getSum(j, i) - target));
			if (j < i)
				res = min(res, abs(getSum(j + 1, i) - target));
		}

		return res;
	}
};
