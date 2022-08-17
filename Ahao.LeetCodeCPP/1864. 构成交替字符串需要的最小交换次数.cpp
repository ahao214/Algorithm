#include<vector>
#include<string>

using namespace std;


/*
1864. ���ɽ����ַ�����Ҫ����С��������
����һ���������ַ��� s ������Ҫ����ת��Ϊһ�� �����ַ��� ��������㲢����ת������� ��С �ַ���������������޷����ת�������� -1 ��

�����ַ��� ��ָ�������ַ�֮�䲻�������������ַ��������磬�ַ��� "010" �� "1010" ���ڽ����ַ������� "0100" ���ǡ�

���������ַ������Խ��н������������� ��
*/
class Solution {
public:
	int get(string a, string b)
	{
		int x = 0, y = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
			{
				if (a[i] == '0') x++;
				else y++;
			}
		}
		if (x != y) return INT_MAX;
		return x;
	}

	int minSwaps(string s) {
		int n = s.size();
		string a(n, '0'), b(n, '0');
		for (int i = 1; i < n; i += 2) a[i] = '1';
		for (int i = 0; i < n; i += 2) b[i] = '1';
		int res = min(get(s, a), get(s, b));
		if (res == INT_MAX) return -1;
		return res;
	}

};
