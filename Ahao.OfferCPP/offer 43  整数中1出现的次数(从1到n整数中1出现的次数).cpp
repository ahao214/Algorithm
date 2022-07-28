#include<vector>

using namespace std;


/*
offer 43  整数中1出现的次数(从1到n整数中1出现的次数)
*/
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n) {
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			num += NumberOf1(i);
		}
		return num;
	}

	int NumberOf1(int i)
	{
		int num = 0;
		while (i)
		{
			if (i % 10 == 1)
				num++;
			i /= 10;
		}
		return num;
	}


	int NumberOf1Between1AndN_Solution(int n) {
		int digit = 1, res = 0;
		int high = n / 10, cur = n % 10, low = 0;
		while (high || cur)
		{
			if (cur == 0) res += high * digit;
			else if (cur == 1) res += high * digit + low + 1;
			else res += (high + 1) * digit;

			low += cur * digit;
			cur = high % 10;
			high /= 10;
			digit *= 10;
		}
		return res;
	}
};