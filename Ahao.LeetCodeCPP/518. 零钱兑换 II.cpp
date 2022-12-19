#include<vector>

using namespace std;


/*
518. ��Ǯ�һ� II
����һ���������� coins ��ʾ��ͬ����Ӳ�ң�
���һ������ amount ��ʾ�ܽ�

������㲢���ؿ��Դճ��ܽ���Ӳ���������
����κ�Ӳ����϶��޷��ճ��ܽ����� 0 ��

����ÿһ������Ӳ�������޸���

��Ŀ���ݱ�֤������� 32 λ������������
*/
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> f(amount + 1);
		f[0] = 1;
		for (auto c : coins)
		{
			for (int i = c; i <= amount; i++)
				f[i] += f[i - c];
		}
		return f[amount];
	}
};