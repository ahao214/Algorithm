#include<vector>

using namespace std;


/*
326. 3 ����
����һ��������дһ���������ж����Ƿ��� 3 ���ݴη�������ǣ����� true �����򣬷��� false ��

���� n �� 3 ���ݴη������㣺�������� x ʹ�� n == 3x
*/
class Solution {
public:
	bool isPowerOfThree(int n) {
		//3^19 = 1162261467
		return n > 0 && 1162261467 % n == 0;
	}
};