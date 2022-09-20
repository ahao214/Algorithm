#include<vector>
#include<string>

using namespace std;


/*
1784. 检查二进制字符串字段
给你一个二进制字符串 s ，该字符串 不含前导零 。

如果 s 包含 零个或一个由连续的 '1' 组成的字段 ，返回 true​​​ 。否则，返回 false 。
*/
class Solution {
public:
	bool checkOnesSegment(string s) {
		int i = 0, j = s.size() - 1;
		while (i <= j && s[i] == '0') i++;
		while (i <= j && s[j] == '0') j--;
		for (int k = i; k <= j; k++)
		{
			if (s[k] == '0')
				return false;
		}
		return true;
	}
};
