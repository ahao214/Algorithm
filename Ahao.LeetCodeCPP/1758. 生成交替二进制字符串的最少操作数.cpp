#include<string>

using namespace std;



/*
1758. ���ɽ���������ַ��������ٲ�����
����һ�������ַ� '0' �� '1' ��ɵ��ַ��� s ��һ�������У�����Խ���һ '0' ��� '1' �����߽� '1' ��� '0' ��

�����ַ��� ����Ϊ������ַ����в��������������ַ���ȵ��������ô���ַ������ǽ����ַ��������磬�ַ��� "010" �ǽ����ַ��������ַ��� "0100" ���ǡ�

����ʹ s ��� �����ַ��� ����� ���� ��������
*/
class Solution {
public:
	int work(char c, string s)
	{
		int res = 0;
		for (auto x : s)
		{
			if (c == x) res++;
			c ^= 1;
		}
		return res;
	}

	int minOperations(string s) {
		return min(work('0', s), work('1', s));
	}
};

