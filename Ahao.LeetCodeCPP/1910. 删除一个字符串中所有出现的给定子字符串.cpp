#include<vector>
#include<string>

using namespace std;



/*
1910. ɾ��һ���ַ��������г��ֵĸ������ַ���
���������ַ��� s �� part ������� s ����ִ�����²���ֱ�� ���� ���ַ��� part ����ɾ����

�ҵ� s �� ����� �����ַ��� part ���������� s ��ɾ����
���㷵�ش� s ��ɾ������ part ���ַ����Ժ�õ���ʣ���ַ�����

һ�� ���ַ��� ��һ���ַ������������ַ����С�
*/
class Solution {
public:
	string removeOccurrences(string s, string part) {
		while (true)
		{
			int k = s.find(part);
			if (k == -1) break;
			s = s.substr(0, k) + s.substr(k + part.size());
		}
		return s;
	}
};

