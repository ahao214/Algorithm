using namespace std;

#include<string>

/*
67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。
*/
class Solution {
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




/*
67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）
输入为 非空 字符串且只包含数字 1 和 0。
*/
class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;
		string res;
		for (int i = 0; i < a.size() || i < b.size(); i++)
		{
			int va = i >= a.size() ? 0 : a[i] - '0';
			int vb = i >= b.size() ? 0 : b[i] - '0';
			int s = va + vb + carry;
			carry = s / 2, s %= 2;
			res += to_string(s);
		}
		if (carry) res += "1";
		return string(res.rbegin(), res.rend());
	}
};