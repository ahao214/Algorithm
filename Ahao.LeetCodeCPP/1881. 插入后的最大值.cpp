#include<vector>
#include<string>

using namespace std;


/*
1881. 插入后的最大值
给你一个非常大的整数 n 和一个整数数字 x ，大整数 n 用一个字符串表示。n 中每一位数字和数字 x 都处于闭区间 [1, 9] 中，且 n 可能表示一个 负数 。

你打算通过在 n 的十进制表示的任意位置插入 x 来 最大化 n 的 数值 ​​​​​​。但 不能 在负号的左边插入 x 。

例如，如果 n = 73 且 x = 6 ，那么最佳方案是将 6 插入 7 和 3 之间，使 n = 763 。
如果 n = -55 且 x = 2 ，那么最佳方案是将 2 插在第一个 5 之前，使 n = -255 。
返回插入操作后，用字符串表示的 n 的最大值。
*/
class Solution {
public:
	string maxValue(string n, int x) {
		if (n[0] != '-')
		{
			int k = 0;
			while (k < n.size() && n[k] - '0' >= x) k++;
			return n.substr(0, k) + to_string(x) + n.substr(k);
		}
		else
		{
			int k = 1;
			while (k < n.size() && n[k] - '0' <= x) k++;
			return n.substr(0, k) + to_string(x) + n.substr(k);
		}
	}

};