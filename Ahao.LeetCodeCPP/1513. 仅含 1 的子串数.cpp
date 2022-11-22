#include<vector>
#include<string>

using namespace std;


/*
1513. 仅含 1 的子串数
给你一个二进制字符串 s（仅由 '0' 和 '1' 组成的字符串）。

返回所有字符都为 1 的子字符串的数目。

由于答案可能很大，请你将它对 10^9 + 7 取模后返回。
*/
class Solution {
public:
	/*
	求出每一段中1的个数(x)，这一段中1的个数是x*(x+1)/2
	两个0之间则为一段，使用双指针
	*/
	int numSub(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '0')
			{
				int j = i + 1;
				while (j < s.size() && s[j] == '1')
					j++;
				int x = j - i;
				res = (res + x * (x + 1ll) / 2) % 1000000007;
				i = j - 1;
			}
		}
		return res;
	}
};