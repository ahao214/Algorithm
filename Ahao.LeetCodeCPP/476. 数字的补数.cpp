#include<vector>

using namespace std;


/*
476. ���ֵĲ���
�������Ķ����Ʊ�ʾȡ����0 �� 1 ��1 �� 0������ת��Ϊʮ���Ʊ�ʾ�����Եõ���������Ĳ�����

���磬���� 5 �Ķ����Ʊ�ʾ�� "101" ��ȡ����õ� "010" ����ת��ʮ���Ʊ�ʾ�õ����� 2 ��
����һ������ num ��������Ĳ�����
*/
class Solution {
public:
	int findComplement(int num) {
		int res = 0, t = 0;
		while (num) {
			res += !(num & 1) << t;
			num >>= 1, t++;
		}
		return res;
	}
};