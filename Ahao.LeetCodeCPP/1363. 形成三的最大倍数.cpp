#include<vector>
#include<string>

using namespace std;


/*
1363. 形成三的最大倍数
给你一个整数数组 digits，你可以通过按任意顺序连接其中某些数字来形成
3的倍数，请你返回所能得到的最大的 3 的倍数。

由于答案可能不在整数数据类型范围内，请以字符串形式返回答案。

如果无法得到答案，请返回一个空字符串。
*/
class Solution {
public:
	string largestMultipleOfThree(vector<int>& digits) {
		int n = digits.size();
		sort(digits.begin(), digits.end());
		vector<vector<int>> f(n + 1, vector<int>(3));

		f[0][1] = f[0][2] = -1e8;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = max(f[i - 1][j], f[i - 1][(j + 3 - digits[i - 1] % 3) % 3] + 1);
			}
		}
		if (f[n][0] <= 0) return "";

		string res;
		for (int i = n, j = 0; i; i--)
		{
			if (f[i][j] == f[i - 1][(j + 3 - digits[i - 1] % 3) % 3] + 1)
			{
				res += to_string(digits[i - 1]);
				j = (j + 3 - digits[i - 1] % 3) % 3;
				if (res == "0") return res;
			}
		}

		return res;
	}
};