#include<vector>

using namespace std;


/*
343. �������
����һ�������� n ��������Ϊ k �� ������ �ĺͣ� k >= 2 ������ʹ��Щ�����ĳ˻���󻯡�

���� ����Ի�õ����˻� ��
*/
class Solution {
public:
	int integerBreak(int n) {
		if (n <= 3) return n - 1;
		int res = 1;
		if (n % 3 == 1) res *= 4, n -= 4;
		else if (n % 3 == 2) res *= 2, n -= 2;
		while (n > 0) res *= 3, n -= 3;
		return res;
	}
};
