#include<vector>
#include<string>

using namespace std;


/*
1864. 构成交替字符串需要的最小交换次数
给你一个二进制字符串 s ，现需要将其转化为一个 交替字符串 。请你计算并返回转化所需的 最小 字符交换次数，如果无法完成转化，返回 -1 。

交替字符串 是指：相邻字符之间不存在相等情况的字符串。例如，字符串 "010" 和 "1010" 属于交替字符串，但 "0100" 不是。

任意两个字符都可以进行交换，不必相邻 。
*/
class Solution {
public:
	int get(string a, string b)
	{
		int x = 0, y = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
			{
				if (a[i] == '0') x++;
				else y++;
			}
		}
		if (x != y) return INT_MAX;
		return x;
	}

	int minSwaps(string s) {
		int n = s.size();
		string a(n, '0'), b(n, '0');
		for (int i = 1; i < n; i += 2) a[i] = '1';
		for (int i = 0; i < n; i += 2) b[i] = '1';
		int res = min(get(s, a), get(s, b));
		if (res == INT_MAX) return -1;
		return res;
	}

};
