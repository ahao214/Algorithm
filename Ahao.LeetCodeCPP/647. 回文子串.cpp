#include<vector>
#include <string>

using namespace std;


/*
647. �����Ӵ�

����һ���ַ��� s ������ͳ�Ʋ���������ַ����� �����Ӵ� ����Ŀ��

�����ַ��� �����Ŷ��͵�������һ�����ַ�����

���ַ��� ���ַ����е��������ַ���ɵ�һ�����С�

���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ���
*/
class Solution {
public:
	int countSubstrings(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			//ö�ٳ���Ϊ���������
			for (int j = i, k = i; j >= 0 && k < s.size(); j--, k++)
			{
				if (s[j] != s[k])
					break;
				res++;
			}
			//ż�����
			for (int j = i, k = i + 1; j >= 0 && k < s.size(); j--, k++)
			{
				if (s[j] != s[k])
					break;
				res++;
			}
		}
		return res;
	}
};
