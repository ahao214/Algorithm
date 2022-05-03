using namespace std;
#include<string>
#include<vector>

class Solution {
	/*
	43. 字符串相乘
	给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

	注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
	*/
public:
	string multiply(string num1, string num2) {
		int n = num1.size();
		int m = num2.size();
		vector<int> v(n + m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int a = num1[n - i - 1] - '0';
				int b = num2[m - j - 1] - '0';
				v[i + j] += a * b;
			}
		}
		for (int i = 0, carry = 0; i < v.size(); i++)
		{
			v[i] += carry;
			carry = v[i] / 10;
			v[i] %= 10;
		}
		string ans;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			if (ans.empty() && v[i] == 0)
				continue;
			ans += v[i] + '0';
		}
		return ans.empty() ? "0" : ans;
	}
};
