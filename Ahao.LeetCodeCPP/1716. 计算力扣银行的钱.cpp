#include<vector>

using namespace std;



/*
1716. �����������е�Ǯ
Hercy ��ҪΪ�����һ������Ǯ���� ÿ�� ���������������Ǯ��

�ʼ��������һ��ʱ����� 1 ��Ǯ�����ܶ������գ���ÿ�춼��ǰһ������ 1 ��Ǯ���ڽ�����ÿһ����һ��������� ǰһ����һ ����� 1 ��Ǯ��

���� n �����㷵���ڵ� n �������ʱ���������������ܹ����˶��ٿ�Ǯ��
*/
class Solution {
public:
	int totalMoney(int n) {
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			int row = (i - 1) / 7, col = (i - 1) % 7;
			res += row + col + 1;
		}
		return res;
	}
};