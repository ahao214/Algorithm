#include<vector>

using namespace std;


/*
1780. �ж�һ�������Ƿ���Ա�ʾ�������ݵĺ�
����һ������ n ���������Խ� n ��ʾ�����ɸ���ͬ��������֮�ͣ����㷵�� true �������뷵�� false ��

����һ������ y ������������� x ���� y == 3^x �����ǳ�������� y �������ݡ�
*/
class Solution {
public:
	bool checkPowersOfThree(int n) {
		while (n)
		{
			if (n % 3 == 2) return false;
			n /= 3;
		}
		return true;
	}
};