#include<string>

using namespace std;


/*
offer 44 数字序列中某一位的数字
*/
class Solution {
public:
	int findNthDigit(int n) {
		if (n <= 9) return n;
		long long sum = 1, bit = 1, tmp = 9 * (int)pow(10, bit - 1) * bit;
		while (n >= sum + tmp)
		{
			sum += tmp;
			bit++;
			tmp = 9 * (int)pow(10, bit - 1) * bit;
		}
		int idx = (n - sum) / bit;
		int idx2 = (n - sum) % bit;
		return to_string(pow(10, bit - 1) + idx)[idx2] - '0';
	}
};