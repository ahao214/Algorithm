#include<vector>
#include<string>

using namespace std;


/*
1839. ����Ԫ����˳���Ų�������ַ���
��һ���ַ���������������ʱ�����ǳ����� ������ ��

���� 5 ��Ӣ��Ԫ����ĸ��'a' ��'e' ��'i' ��'o' ��'u'�������� ���� ����һ�Ρ�
��ЩԪ����ĸ��˳�򶼱��밴�� �ֵ��� �����Ų���Ҳ����˵���е� 'a' ���� 'e' ǰ�棬���е� 'e' ���� 'i' ǰ�棬�Դ����ƣ�
�ȷ�˵���ַ��� "aeiou" �� "aaaaaaeiiiioou" ���� ������ ������ "uaeio" ��"aeoiu" �� "aaaeeeooo" ���������� ��

����һ��ֻ����Ӣ��Ԫ����ĸ���ַ��� word �����㷵�� word �� ��������ַ����ĳ��� ��������������������ַ������뷵�� 0 ��

���ַ��� ���ַ�����һ���������ַ����С�
*/
class Solution {
public:
	int longestBeautifulSubstring(string word) {
		int res = 0;
		string p = "aeiou";
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] != 'a') continue;
			int j = i, k = 0;
			while (j < word.size())
			{
				if (word[j] == p[k])
				{
					j++;
				}
				else
				{
					if (k == 4) break;
					if (word[j] == p[k + 1])j++, k++;
					else break;
				}
				if (k == 4) res = max(res, j - i);
			}
			i = j - 1;
		}
		return res;
	}
};

