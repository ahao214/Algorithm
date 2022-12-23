#include<vector>

using namespace std;


/*
263. ����
����һ������ n �������ж� n �Ƿ�Ϊ ���� ������ǣ����� true �����򣬷��� false ��

���� ����ֻ���������� 2��3 ��/�� 5 ����������
*/
class Solution {
public:
	bool isUgly(int n) {
		int d[] = { 2,3,5 };
		for (auto prime : d)
		{
			while (n > 0 && n % prime == 0)
				n /= prime;
		}
		return n == 1;
	}
};