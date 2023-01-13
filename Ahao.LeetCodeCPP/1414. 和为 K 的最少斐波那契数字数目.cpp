#include<vector>

using namespace std;


/*
1414. 和为 K 的最少斐波那契数字数目
给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
数据保证对于给定的 k ，一定能找到可行解。
*/
class Solution {
public:
	int findMinFibonacciNumbers(int k) {
		if (k <= 0) return 0;
		int a = 1, b = 1;
		while (a + b <= k) {
			b = a + b;
			a = b - a;
		}
		return findMinFibonacciNumbers(k - b) + 1;
	}
};



