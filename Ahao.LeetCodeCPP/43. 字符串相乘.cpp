using namespace std;
#include<string>
#include<vector>

class Solution {
	/*
	43. �ַ������
	�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��

	ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������
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




/*
43. �ַ������
�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��

ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������
*/
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> product(num1.size() + num2.size(), 0);
		for (int i = 0; i < num1.size(); i++)
		{
			for (int j = 0; j < num2.size(); j++)
			{
				product[num1.size() - i + num2.size() - j - 2] += (num1[i] - '0') * (num2[j] - '0');
			}
		}
		int t = 0;
		for (int i = 0; i < product.size(); i++)
		{
			int& x = product[i];
			t += x;
			x = t % 10;
			t /= 10;
		}
		string res;
		int k = product.size() - 1;
		while (!product[k] && k > 0) k--;
		for (int i = k; i >= 0; i--)
		{
			res += to_string(product[i]);
		}
		return res;
	}
};