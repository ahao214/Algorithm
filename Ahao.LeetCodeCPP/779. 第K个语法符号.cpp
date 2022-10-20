#include<vector>

using namespace std;

//递归
class Solution {
public:
	int kthGrammar(int n, int k) {
		if (n == 1) {
			return 0;
		}
		return (k & 1) ^ 1 ^ kthGrammar(n - 1, (k + 1) / 2);
	}
};


//找规律+递归
class Solution {
public:
	int kthGrammar(int n, int k) {
		if (k == 1) {
			return 0;
		}
		if (k > (1 << (n - 2))) {
			return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));
		}
		return kthGrammar(n - 1, k);
	}
};


//找规律+位运算
class Solution {
public:
	int kthGrammar(int n, int k) {
		// return __builtin_popcount(k - 1) & 1;
		k--;
		int res = 0;
		while (k > 0) {
			k &= k - 1;
			res ^= 1;
		}
		return res;
	}
};
