#include<vector>


using namespace std;


/*
offer 10 ì³²¨ÄÇÆõÊıÁĞ
*/
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 0)return 0;
		if (n == 1)return 1;
		int a = 0, b = 1, res = 0;
		for (int i = 2; i <= n; ++i)
		{
			res = a + b;
			a = b;
			b = res;
		}
		return res;
	}
};