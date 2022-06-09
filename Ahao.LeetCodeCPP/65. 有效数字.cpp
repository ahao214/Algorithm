using namespace std;

#include<vector>
#include<string>

class Solution {
	/*
	65. ��Ч����
	��Ч���֣���˳�򣩿��Էֳ����¼������֣�

	һ�� С�� ���� ����
	����ѡ��һ�� 'e' �� 'E' ���������һ�� ����
	С������˳�򣩿��Էֳ����¼������֣�

	����ѡ��һ�������ַ���'+' �� '-'��
	������ʽ֮һ��
	����һλ���֣��������һ���� '.'
	����һλ���֣��������һ���� '.' �������ٸ�������һλ����
	һ���� '.' �������������һλ����
	��������˳�򣩿��Էֳ����¼������֣�

	����ѡ��һ�������ַ���'+' �� '-'��
	����һλ����
	������Ч�����о����£�["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]

	������Ч�����о����£�["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]

	����һ���ַ��� s ����� s ��һ�� ��Ч���� ���뷵�� true ��
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	bool isNumber(string s) {
		int idx = -1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'e' || s[i] == 'E')
			{
				if (idx == -1) idx = i;
				else
					return false;
			}
		}
		if (idx == -1) {
			return check(s, 0, s.length() - 1, false);
		}
		return check(s, 0, idx - 1, false) && check(s, idx + 1, s.length() - 1, true);
	}

	bool check(string& s, int start, int end, bool mustInt) {
		if (s[start] == '+' || s[start] == '-') start++;
		bool point = false, digit = false;
		for (int i = start; i <= end; i++)
		{
			if (s[i] == '.') {
				if (point || mustInt) return false;
				point = true;
			}
			else if (isdigit(s[i])) {
				digit = true;
			}
			else {
				return false;
			}
		}
		return digit;
	}
};
