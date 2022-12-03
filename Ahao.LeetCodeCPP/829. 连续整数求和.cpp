using namespace std;
#include<string>


class Solution {
public:
	int consecutiveNumbersSum(int n) {
		int ans = 0;
		int bound = 2 * n;
		for (int k = 1; k * (k + 1) <= bound; k++) {
			if (isKConsecutive(n, k)) {
				ans++;
			}
		}
		return ans;
	}

	bool isKConsecutive(int n, int k) {
		if (k % 2 == 1) {
			return n % k == 0;
		}
		else {
			return n % k != 0 && 2 * n % k == 0;
		}
	}
};




/*
829. 连续整数求和
给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。
*/
class Solution {
public:
	int consecutiveNumbersSum(int n) {
		int res = 0;
		for (int b = 1; b * (b - 1) < n * 2; b++)
		{
			if (2 * n % b == 0 && (2 * n / b - b + 1) % 2 == 0)
				res++;
		}
		return res;
	}
};