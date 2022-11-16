#include<vector>
#include<string>
#include <numeric>
using namespace std;


using namespace std;


/*
1625. ִ�в������ֵ�����С���ַ���
*/
class Solution {
public:
	string findLexSmallestString(string s, int a, int b) {
		int n = s.size();
		string ret = s;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				string t = s;
				if (b % 2 == 1)
				{
					for (int k = 0; k < n; k += 2)
						t[k] = (t[k] - '0' + i * a) % 10 + '0';
				}
				for (int k = 1; k < n; k += 2)
				{
					t[k] = (t[k] - '0' + j * a) % 10 + '0';
				}
				string p = t;
				for (int k = 0; k <= n / gcd(n, b); k++)
				{
					p = p.substr(n - b) + p.substr(0, n - b);
					ret = min(ret, p);
				}
			}
		}
		return ret;
	}

	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
};


/*
1625. ִ�в������ֵ�����С���ַ���
����һ���ַ��� s �Լ��������� a �� b �����У��ַ��� s �ĳ���Ϊż�����ҽ������� 0 �� 9 ��ɡ�

������� s �ϰ�����˳����ִ��������������֮һ��

�ۼӣ���  a �ӵ� s �������±�Ϊ������Ԫ���ϣ��±�� 0 ��ʼ��������һ������ 9 �ͻ��� 0�����ѭ�����������磬s = "3456" �� a = 5����ִ�д˲����� s ��� "3951"��
��ת���� s ������ת b λ�����磬s = "3456" �� b = 1����ִ�д˲����� s ��� "6345"��
���㷵���� s ��ִ��������������κ���Եõ��� �ֵ�����С ���ַ�����

��������ַ���������ͬ����ô�ַ��� a �ֵ�����ַ��� b С�����������壺�� a �� b ���ֲ�ͬ�ĵ�һ��λ���ϣ��ַ��� a �е��ַ���������ĸ���е�ʱ������ b �еĶ�Ӧ�ַ������磬"0158�� �ֵ���� "0190" С����Ϊ��ͬ�ĵ�һ��λ�����ڵ������ַ�����Ȼ '5' ������ '9' ֮ǰ��
*/
class Solution {
public:
	void update(char& c, int a)
	{
		c = '0' + (c - '0' + a) % 10;
	}

	string findLexSmallestString(string s, int a, int b) {
		int n = s.size();
		string res = s;
		if (b % 2 == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 1; j <= n; j += 2)
					update(s[j], a);

				for (int j = 0; j < n; j++)
				{
					s = s.substr(n - b) + s.substr(0, n - b);
					res = min(res, s);
				}
			}
			return res;
		}
		else {
			for (int i = 0; i < 10; i++)
			{
				for (int j = 1; j < n; j += 2) update(s[j], a);
				for (int j = 0; j < 10; j++)
				{
					for (int k = 0; k < n; k += 2) update(s[k], a);
					for (int k = 0; k < n; k++)
					{
						s = s.substr(n - b) + s.substr(0, n - b);
						res = min(res, s);
					}
				}
			}
		}
		return res;
	}
};
