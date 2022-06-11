using namespace std;

#include<string>


class Solution {
	/*
	67. 二进制求和
	给你两个二进制字符串，返回它们的和（用二进制表示）。

	输入为 非空 字符串且只包含数字 1 和 0。
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	string addBinary(string a, string b) {
		/*定义两个下标,分别指向a和b的最后一位,计算之后,下标往前移动*/
		string ans;
		int carry = 0; //进位
		int i = a.length() - 1, j = b.length() - 1;
		while (i >= 0 || j >= 0 || carry)
		{
			if (i >= 0) carry += a[i--] - '0';
			if (j >= 0) carry += b[j--] - '0';
			ans = to_string(carry % 2) + ans;
			carry /= 2;
		}
		return ans;
	}

};