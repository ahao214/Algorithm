using namespace std;
#include<string>;

#pragma region 16. �滻�ո�

/*
��ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��

���ݷ�Χ
0�� �����ַ����ĳ��� ��1000��
ע������ַ����ĳ��ȿ��ܴ��� 1000��

����
���룺"We are happy."

�����"We%20are%20happy."
*/

/*
��ǰ����ö��ԭ�ַ�����

��������ո�����string���͵Ĵ������ "%20"��
������������ַ�����ֱ�ӽ�������ڴ��У�

ʱ�临�Ӷȷ���
ԭ�ַ���ֻ�ᱻ���������Σ�������ʱ�临�Ӷ��� O(n)O(n)��
*/

#pragma endregion

class Solution {
public:
	string replaceSpaces(string& str) {
		string res;
		for (auto& c : str)
		{
			if (c == ' ')
				res += "%20";
			else
				res += c;
		}
		return res;
	}
};