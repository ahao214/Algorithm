#include <unordered_set>
using namespace std;


class Solution {
	bool isPrime(int x) {
		if (x < 2) {
			return false;
		}
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}

public:
	int countPrimeSetBits(int left, int right) {
		int ans = 0;
		for (int x = left; x <= right; ++x) {
			if (isPrime(__builtin_popcount(x))) {
				++ans;
			}
		}
		return ans;
	}

	//判断质数优化
	int countPrimeSetBits2(int left, int right) {
		int ans = 0;
		for (int x = left; x <= right; ++x) {
			if ((1 << __builtin_popcount(x)) & 665772) {
				++ans;
			}
		}
		return ans;
	}
};


/*
762. 二进制表示中质数个计算置位
给定两个整数L和R ，找到闭区间[L, R]范围内，计算置位位数为质数的整数个数。

（注意，计算置位代表二进制表示中1的个数。
例如 21 的二进制表示10101有3个计算置位。还有，1 不是质数。）

示例 1:
*/
class Solution {
public:
	int countPrimeSetBits(int left, int right) {
		unordered_set<int> primes({ 2,3,5,7,11,13,17,19 });

		int res = 0;
		for (int i = left; i <= right; i++) {
			int s = 0;
			for (int k = i; k; k >>= 1)
				s += k & 1;
			if (primes.count(s))
				res++;
		}
		return res;
	}
};
