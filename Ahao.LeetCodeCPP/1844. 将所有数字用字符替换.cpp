#include<vector>
#include<string>

using namespace std;



/*
1844. �������������ַ��滻
����һ���±�� 0 ��ʼ���ַ��� s ������ ż�� �±괦ΪСдӢ����ĸ������ �±괦Ϊ���֡�

����һ������ shift(c, x) ������ c ��һ���ַ��� x ��һ�����֣�����������ĸ���� c ����� x ���ַ���

�ȷ�˵��shift('a', 5) = 'f' �� shift('x', 0) = 'x' ��
����ÿ�� ���� �±� i ������Ҫ������ s[i] �� shift(s[i-1], s[i]) �滻��

�����滻���������Ժ󣬽��ַ��� s ���ء���Ŀ ��֤ shift(s[i-1], s[i]) ���ᳬ�� 'z' ��
*/
class Solution {
public:
	string replaceDigits(string s) {
		for (int i = 1; i < s.size(); i += 2)
			s[i] = s[i - 1] + s[i] - '0';
		return s;
	}
};