#include<vector>
#include<string>

using namespace std;


/*
1869. �����������ַ�������
����һ���������ַ��� s ������ַ������� 1 ��ɵ� � �������ַ��� �ϸ��� �� 0 ��ɵ� � �������ַ��������� true �����򣬷��� false ��

���磬s = "110100010" �У��� 1 ��ɵ���������ַ����ĳ����� 2 ���� 0 ��ɵ���������ַ����ĳ����� 3 ��
ע�⣬����ַ����в����� 0 ����ʱ��Ϊ�� 0 ��ɵ���������ַ����ĳ����� 0 ���ַ����в����� 1 �����Ҳ���ô˹���
*/
class Solution {
public:
	bool checkZeroOnes(string s) {
		int one = 0, zero = 0;
		int s1 = 0, s0 = 0;
		for (auto c : s)
		{
			if (c == '0') s0++, s1 = 0;
			else s1++, s0 = 0;
			one = max(one, s1), zero = max(zero, s0);
		}
		return one > zero;
	}
};