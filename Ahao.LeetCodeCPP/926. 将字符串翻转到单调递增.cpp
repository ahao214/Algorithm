#include<vector>
#include <string>

using namespace std;



/*
926. 将字符串翻转到单调递增

如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。

给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。

返回使 s 单调递增的最小翻转次数。
*/
class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int res = 0, num = 0;
		for (auto& c : s) {
			if (c == '1') {
				num++;
			}
			else {
				res = min(num, res + 1);
			}
		}
		return res;
	}
};




/*
926. 将字符串翻转到单调递增

如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。

给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。

返回使 s 单调递增的最小翻转次数。
*/
class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int n = s.size();
		vector<int> c(n + 1);
		for (int i = 1; i <= n; i++)
		{
			c[i] = c[i - 1] + s[i - 1] - '0';
		}
		int res = n - c[n];
		for (int i = 1; i <= n; i++)
			res = min(res, c[i] + n - i - (c[n] - c[i]));
		return res;
	}
};