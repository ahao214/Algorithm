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

