#include<vector>
#include<string>

using namespace std;


/*
1903. �ַ����е��������
����һ���ַ��� num ����ʾһ�����������������ַ��� num ������ �ǿ����ַ��� ���ҳ� ֵ�������� �������ַ�����ʽ���ء�����������������򷵻�һ�����ַ��� "" ��

���ַ��� ���ַ����е�һ���������ַ����С�
*/
class Solution {
public:
	//�ҵ��ұ����һ������
	string largestOddNumber(string num) {
		int k = num.size() - 1;
		while (k >= 0 && num[k] % 2 == 0) k--;
		if (k < 0) return "";
		return num.substr(0, k + 1);
	}

};