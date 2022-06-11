using namespace std;

#include<string>


class Solution {
	/*
	67. ���������
	���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

	����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0��
	*/
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