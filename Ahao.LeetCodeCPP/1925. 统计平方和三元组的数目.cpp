#include<vector>

using namespace std;

/*
1925. ͳ��ƽ������Ԫ�����Ŀ
һ�� ƽ������Ԫ�� (a,b,c) ָ�������� a^2 + b^2 = c^2 �� ���� ��Ԫ�� a��b �� c ��

����һ������ n �����㷵������ 1 <= a, b, c <= n �� ƽ������Ԫ�� ����Ŀ��
*/
class Solution {
public:
	int countTriples(int n) {
		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					if (i * i + j * j == k * k)
						res++;
		return res;
	}
};

