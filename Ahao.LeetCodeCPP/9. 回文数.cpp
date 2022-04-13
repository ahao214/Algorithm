using namespace std;
#include<string>

class Solution {
	/*
	9. ������
	����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

	��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ�������������磬121 �ǻ��ģ��� 123 ���ǡ�
	*/
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int num = x, cur = 0;
		while (x) {
			if (cur > (INT_MAX - x % 10) / 10)
				return false;
			cur = cur * 10 + x % 10;
			x /= 10;
		}
		return cur == num;
	}
};
