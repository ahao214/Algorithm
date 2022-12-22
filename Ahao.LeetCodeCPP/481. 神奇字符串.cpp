#include<string>

using namespace std;

class Solution {
public:
	int magicalString(int n) {
		if (n < 4) {
			return 1;
		}
		string s(n, '0');
		s[0] = '1', s[1] = '2', s[2] = '2';
		int res = 1;
		int i = 2;
		int j = 3;
		while (j < n) {
			int size = s[i] - '0';
			int num = 3 - (s[j - 1] - '0');
			while (size > 0 && j < n) {
				s[j] = '0' + num;
				if (num == 1) {
					++res;
				}
				++j;
				--size;
			}
			++i;
		}
		return res;
	}
};



/*
481. �����ַ���
�����ַ��� s ���� '1' �� '2' ��ɣ�����Ҫ��������Ĺ���

�����ַ��� s ������֮�����ڣ������ַ����� '1' �� '2' ���������ִ����������ɸ��ַ�����
s ��ǰ����Ԫ���� s = "1221121221221121122����" ������� s ������������ 1 �� 2 ���з��飬���Եõ� "1 22 11 2 1 22 1 22 11 2 11 22 ......" ��ÿ���� 1 ���� 2 �ĳ��ִ����ֱ��� "1 2 2 1 1 2 1 2 2 1 2 2 ......" ������ĳ��ִ������� s ����

����һ������ n �������������ַ��� s ��ǰ n �������� 1 ����Ŀ��
*/
class Solution {
public:
	int magicalString(int n) {
		string s = "122";
		for (int i = 2, k = 1; i < n; i++, k = 3 - k)
		{
			for (int j = 0; j < s[i] - '0'; j++)
				s += to_string(k);
		}
		int res = 0;
		for (int i = 0; i < n; i++)
			res += s[i] == '1';
		return res;
	}
};
