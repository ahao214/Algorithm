#include<vector>
#include<string>

using namespace std;



/*
1717. 删除子字符串的最大得分
给你一个字符串 s 和两个整数 x 和 y 。你可以执行下面两种操作任意次。

删除子字符串 "ab" 并得到 x 分。
比方说，从 "cabxbae" 删除 ab ，得到 "cxbae" 。
删除子字符串"ba" 并得到 y 分。
比方说，从 "cabxbae" 删除 ba ，得到 "cabxe" 。
请返回对 s 字符串执行上面操作若干次能得到的最大得分。
*/
class Solution {
public:
	int maximumGain(string s, int x, int y) {
		if (x < y)
		{
			swap(x, y);
			for (auto& c : s)
			{
				if (c == 'a') c = 'b';
				else if (c == 'b') c = 'a';
			}
		}

		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != 'a' && s[i] != 'b') continue;
			int j = i + 1;
			while (j < s.size() && (s[j] == 'a' || s[j] == 'b')) j++;
			int a = 0, b = 0, c = 0;
			for (int k = j - 1, t = 0; k >= i; k--)
			{
				if (s[k] == 'a')
				{
					a++;
					if (t)
					{
						c++;
						t--;
					}
				}
				else
				{
					b++;
					t++;
				}
			}
			res += c * x + (min(a, b) - c) * y;
			i = j - 1;
		}
		return res;
	}
};