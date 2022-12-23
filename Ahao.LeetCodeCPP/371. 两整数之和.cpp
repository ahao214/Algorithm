#include<vector>

using namespace std;



/*
371. 两整数之和
给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
*/
class Solution {
public:
	int getSum(int a, int b) {
		if (!b) return a;
		unsigned int carry = (unsigned int)(a & b) << 1;
		unsigned sum = a ^ b;
		return getSum(sum, carry);
	}
};