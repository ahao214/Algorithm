#include<vector>
#include<string>

using namespace std;


/*
1759. 统计同构子字符串的数目
给你一个字符串 s ，返回 s 中 同构子字符串 的数目。由于答案可能很大，只需返回对 109 + 7 取余 后的结果。

同构字符串 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同构字符串。

子字符串 是字符串中的一个连续字符序列。
*/
class Solution {
public:
	/*
	先将字符串分成几段，使每段里面的字符都相同
	计算每段里面子字符串的个数，假设每段的长度为K，个数为 k*(k+1)/2
	*/
	int countHomogenous(string s) {
		typedef long long LL;
		const int MOD = 1e9 + 7;

		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i + 1;
			while (j < s.size() && s[j] == s[i])
				j++;
			int k = j - i;
			res = (res + (LL)k * (k + 1) / 2) % MOD;
			i = j - 1;
		}
		return res;
	}
};
