using namespace std;

#include<string>

/*
67. ���������
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0��
*/
class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	string addBinary(string a, string b) {
		/*���������±�,�ֱ�ָ��a��b�����һλ,����֮��,�±���ǰ�ƶ�*/
		string ans;
		int carry = 0; //��λ
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
67. ���������
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ��
����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0��
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