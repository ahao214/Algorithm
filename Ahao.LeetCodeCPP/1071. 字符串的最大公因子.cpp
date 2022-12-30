#include<vector>
#include <string>

using namespace std;


/*
1071. �ַ������������
�����ַ��� S �� T��ֻ���� S = T + ... + T��T �������� 1 �λ��Σ�ʱ�����ǲ��϶� ��T �ܳ��� S����

������ַ��� X��Ҫ������ X �ܳ��� str1 �� X �ܳ��� str2��
*/
class Solution {
public:
	/*
	�Ƚ������ַ����ĳ���
	�ӳ��ȳ����ַ����м�ȥ���ȶ̵��ַ������ڱȽ������ַ����ĳ���
	�ٴδӳ��������ȥ�̵ģ�ֱ��һ��Ϊ��
	*/
	string gcdOfStrings(string str1, string str2) {
		if (str1.size() < str2.size())
		{
			return gcdOfStrings(str2, str1);
		}
		if (str2.empty())
			return str1;
		if (str1.substr(0, str2.size()) != str2)
			return "";
		return gcdOfStrings(str1.substr(str2.size()), str2);
	}
};