#include<vector>
#include <string>

using namespace std;


/*
233. 数字 1 的个数
*/
class Solution {
public:
	int countDigitOne(int n) {
		string s = to_string(n);
		long len = s.size();

		long count = 0;
		for (long i = 1; i <= len; i++)
		{
			long a = n / pow(10, i);
			count += a * pow(10, i - 1);
			if (s[len - i] - '0' > 1)
				count += pow(10, i - 1);
			else if (s[len - i] - '0' == 1)
				count += n % (long)pow(10, i - 1) + 1;
		}
		return count;
	}
};