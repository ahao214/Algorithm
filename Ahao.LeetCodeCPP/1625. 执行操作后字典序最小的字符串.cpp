#include<vector>
#include<string>
#include <numeric>
using namespace std;


using namespace std;


/*
1625. 执行操作后字典序最小的字符串
*/
class Solution {
public:
	string findLexSmallestString(string s, int a, int b) {
		int n = s.size();
		string ret = s;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				string t = s;
				if (b % 2 == 1)
				{
					for (int k = 0; k < n; k += 2)
						t[k] = (t[k] - '0' + i * a) % 10 + '0';
				}
				for (int k = 1; k < n; k += 2)
				{
					t[k] = (t[k] - '0' + j * a) % 10 + '0';
				}
				string p = t;
				for (int k = 0; k <= n / gcd(n, b); k++)
				{
					p = p.substr(n - b) + p.substr(0, n - b);
					ret = min(ret, p);
				}
			}
		}
		return ret;
	}

	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
};


/*
1625. 执行操作后字典序最小的字符串
给你一个字符串 s 以及两个整数 a 和 b 。其中，字符串 s 的长度为偶数，且仅由数字 0 到 9 组成。

你可以在 s 上按任意顺序多次执行下面两个操作之一：

累加：将  a 加到 s 中所有下标为奇数的元素上（下标从 0 开始）。数字一旦超过 9 就会变成 0，如此循环往复。例如，s = "3456" 且 a = 5，则执行此操作后 s 变成 "3951"。
轮转：将 s 向右轮转 b 位。例如，s = "3456" 且 b = 1，则执行此操作后 s 变成 "6345"。
请你返回在 s 上执行上述操作任意次后可以得到的 字典序最小 的字符串。

如果两个字符串长度相同，那么字符串 a 字典序比字符串 b 小可以这样定义：在 a 和 b 出现不同的第一个位置上，字符串 a 中的字符出现在字母表中的时间早于 b 中的对应字符。例如，"0158” 字典序比 "0190" 小，因为不同的第一个位置是在第三个字符，显然 '5' 出现在 '9' 之前。
*/
class Solution {
public:
	void update(char& c, int a)
	{
		c = '0' + (c - '0' + a) % 10;
	}

	string findLexSmallestString(string s, int a, int b) {
		int n = s.size();
		string res = s;
		if (b % 2 == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 1; j <= n; j += 2)
					update(s[j], a);

				for (int j = 0; j < n; j++)
				{
					s = s.substr(n - b) + s.substr(0, n - b);
					res = min(res, s);
				}
			}
			return res;
		}
		else {
			for (int i = 0; i < 10; i++)
			{
				for (int j = 1; j < n; j += 2) update(s[j], a);
				for (int j = 0; j < 10; j++)
				{
					for (int k = 0; k < n; k += 2) update(s[k], a);
					for (int k = 0; k < n; k++)
					{
						s = s.substr(n - b) + s.substr(0, n - b);
						res = min(res, s);
					}
				}
			}
		}
		return res;
	}
};
