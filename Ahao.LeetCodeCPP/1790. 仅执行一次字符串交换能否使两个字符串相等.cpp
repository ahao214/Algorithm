#include<vector>
#include<string>
using namespace std;


/*
1790. ��ִ��һ���ַ��������ܷ�ʹ�����ַ������
���㳤����ȵ������ַ��� s1 �� s2 ��һ�� �ַ������� �����Ĳ������£�ѡ��ĳ���ַ����е������±꣨���ز�ͬ�����������������±�����Ӧ���ַ���

����� ����һ���ַ��� ִ�� ���һ���ַ������� �Ϳ���ʹ�����ַ�����ȣ����� true �����򣬷��� false ��
*/
class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		if (s1 == s2) return true;

		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				swap(s1[i], s1[j]);
				if (s1 == s2)
					return true;
				swap(s1[i], s1[j]);
			}
		}
		return false;
	}
};