#include<vector>
#include<string>

using namespace std;



/*
1871. 跳跃游戏 VII
给你一个下标从 0 开始的二进制字符串 s 和两个整数 minJump 和 maxJump 。一开始，你在下标 0 处，且该位置的值一定为 '0' 。当同时满足如下条件时，你可以从下标 i 移动到下标 j 处：

i + minJump <= j <= min(i + maxJump, s.length - 1) 且
s[j] == '0'.
如果你可以到达 s 的下标 s.length - 1 处，请你返回 true ，否则返回 false 。
*/
class Solution {
public:
	bool canReach(string s, int minJump, int maxJump) {
		int n = s.size();
		vector<int> f(n + 1), str(n + 1);
		f[1] = 1;
		str[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			if (s[i - 1] == '0' && i - minJump >= 1)
			{
				int left = max(1, i - maxJump), right = i - minJump;
				if (str[right] > str[left - 1])
					f[i] = 1;
			}
			str[i] = str[i - 1] + f[i];
		}
		return f[n];
	}
};

