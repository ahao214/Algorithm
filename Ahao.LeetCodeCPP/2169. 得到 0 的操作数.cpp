#include<vector>

using namespace std;


/*
2169. �õ� 0 �Ĳ�����
�������� �Ǹ� ���� num1 �� num2 ��

ÿһ�� ���� �У���� num1 >= num2 ��������� num1 �� num2 ������������� num2 �� num1 ��

���磬num1 = 5 �� num2 = 4 ��Ӧ���� num1 �� num2 ����ˣ��õ� num1 = 1 �� num2 = 4 ��Ȼ������� num1 = 4�� num2 = 5 ��һ�������󣬵õ� num1 = 4 �� num2 = 1 ��
����ʹ num1 = 0 �� num2 = 0 �� ������ ��
*/
class Solution {
public:
	int countOperations(int num1, int num2) {
		int ans = 0;
		while (num1 != 0 && num2 != 0) {
			if (num1 < num2) swap(num1, num2);
			num1 -= num2;
			ans += 1;
		}
		return ans;
	}
};