#include<vector>

using namespace std;


/*
1414. ��Ϊ K ������쳲�����������Ŀ
�������� k �����㷵�غ�Ϊ k ��쳲��������ֵ�������Ŀ�����У�ÿ��쳲��������ֶ����Ա�ʹ�ö�Ρ�

쳲��������ֶ���Ϊ��

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 �� ���� n > 2 ��
���ݱ�֤���ڸ����� k ��һ�����ҵ����н⡣
*/
class Solution {
public:
	int findMinFibonacciNumbers(int k) {
		if (k <= 0) return 0;
		int a = 1, b = 1;
		while (a + b <= k) {
			b = a + b;
			a = b - a;
		}
		return findMinFibonacciNumbers(k - b) + 1;
	}
};



