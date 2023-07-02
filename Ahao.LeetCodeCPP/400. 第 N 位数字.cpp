#include<vector>
#include <string>

using namespace std;




/*
400. µÚ N Î»Êý×Ö
*/
class Solution {
public:
	int findNthDigit(int n) {
		long long k = 1, t = 9, s = 1;
		while (n > t * k)
		{
			n -= t * k;
			k++;
			t *= 10;
			s *= 10;
		}
		s += (n + k - 1) / k - 1;
		n = n % k ? n % k : k;
		return to_string(s)[n - 1] - '0';
	}
};