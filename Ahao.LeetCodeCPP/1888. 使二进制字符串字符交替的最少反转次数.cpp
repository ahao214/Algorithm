#include<vector>
#include<string>

using namespace std;



/*
1888. 使二进制字符串字符交替的最少反转次数
给你一个二进制字符串 s 。你可以按任意顺序执行以下两种操作任意次：

类型 1 ：删除 字符串 s 的第一个字符并将它 添加 到字符串结尾。
类型 2 ：选择 字符串 s 中任意一个字符并将该字符 反转 ，也就是如果值为 '0' ，则反转得到 '1' ，反之亦然。
请你返回使 s 变成 交替 字符串的前提下， 类型 2 的 最少 操作次数 。

我们称一个字符串是 交替 的，需要满足任意相邻字符都不同。

比方说，字符串 "010" 和 "1010" 都是交替的，但是字符串 "0100" 不是。
*/
class Solution {
public:
	int minFlips(string s) {
		int n = s.size();
		vector<int> left[2], right[2];
		left[0] = left[1] = right[0] = right[1] = vector<int>(n);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0, c = 0, k = i; j < n; j++, k ^= 1)
			{
				if (k != s[j] - '0')c++;
				left[i][j] = c;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = n - 1, c = 0, k = i; j >= 0; j--, k ^= 1)
			{
				if (k != s[j] - '0') c++;
				right[i][j] = c;
			}
		}

		if (n % 2 == 0)
			return min(left[0][n - 1], left[1][n - 1]);
		else
		{
			int res = min(left[0][n - 1], left[1][n - 1]);
			for (int i = 0; i + 1 < n; i++)
			{
				res = min(res, left[0][i] + right[1][i + 1]);
				res = min(res, left[1][i] + right[0][i + 1]);
			}
			return res;
		}
	}

};
