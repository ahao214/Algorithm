#include<vector>
#include<string>

using namespace std;


/*
1957. ɾ���ַ�ʹ�ַ������
һ���ַ������û�� �������� ��ͬ�ַ�����ô������һ�� ���ַ��� ��

����һ���ַ��� s ������� s ɾ�� ���� ���ַ���ʹ�����һ�� ���ַ��� ��

���㷵��ɾ������ַ�������Ŀ���ݱ�֤������ Ψһ�� ��
*/
class Solution {
public:
	string makeFancyString(string s) {
		string res;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i + 1;
			while (j < s.size() && s[j] == s[i])
				j++;
			for (int k = 0; k < 2 && k < j - i; k++)
				res += s[i];
			i = j - 1;
		}
		return res;
	}
};



