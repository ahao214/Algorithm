#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
166. ������С��

���������������ֱ��ʾ�����ķ��� numerator �ͷ�ĸ denominator���� �ַ�����ʽ����С�� ��

���С������Ϊѭ��С������ѭ���Ĳ������������ڡ�

������ڶ���𰸣�ֻ�践�� ����һ�� ��

�������и��������룬��֤ ���ַ����ĳ���С�� 104 ��
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
166. ������С��
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