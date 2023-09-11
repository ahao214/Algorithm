#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
166. 分数到小数

给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。
*/
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long n = numerator, d = denominator;
		bool minus = false;
		if (n < 0) minus = !minus, n = -n;
		if (d < 0) minus = !minus, d = -d;
		string res = to_string(n / d);
		n %= d;
		if (!n)
		{
			if (minus && res != "0") return '-' + res;
			return res;
		}
		res += '.';
		unordered_map<long long, int> hash;
		while (n)
		{
			if (hash[n])
			{
				res = res.substr(0, hash[n]) + '(' + res.substr(hash[n]) + ')';
				break;
			}
			else
			{
				hash[n] = res.size();
			}
			n *= 10;
			res += to_string(n / d);
			n %= d;
		}
		if (minus) res = '-' + res;
		return res;
	}
};





/*
166. 分数到小数
*/
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		typedef long long LL;
		LL x = numerator, y = denominator;
		if (x % y == 0) return to_string(x / y);
		string res;
		if ((x < 0) ^ (y < 0)) res += '-';
		x = abs(x), y = abs(y);
		res += to_string(x / y) + '.', x %= y;
		unordered_map<LL, int> hash;
		while (x)
		{
			hash[x] = res.size();
			x *= 10;
			res += to_string(x / y);
			x %= y;
			if (hash.count(x))
			{
				res = res.substr(0, hash[x]) + '(' + res.substr(hash[x]) + ')';
				break;
			}
		}
		return res;
	}
};