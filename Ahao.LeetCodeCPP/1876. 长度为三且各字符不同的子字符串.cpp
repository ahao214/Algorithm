#include<string>

using namespace std;


/*
1876. ����Ϊ���Ҹ��ַ���ͬ�����ַ���
���һ���ַ����������κ��ظ��ַ������ǳ�����ַ���Ϊ �� �ַ�����

����һ���ַ��� s �����㷵�� s �г���Ϊ 3 �� �����ַ��� ��������

ע�⣬�����ͬ�ĺ����ַ������ֶ�Σ�ÿһ�ζ�Ӧ�ñ������֮�С�

���ַ��� ��һ���ַ������������ַ����С�
*/
class Solution {

public:
	int countGoodSubstrings(string s) {
		int res = 0;
		for (int i = 0; i + 2 < s.size(); i++)
		{
			int a = i, b = i + 1, c = i + 2;
			if (s[a] != s[b] && s[b] != s[c] && s[a] != s[c])
				res++;
		}
		return res;
	}

};