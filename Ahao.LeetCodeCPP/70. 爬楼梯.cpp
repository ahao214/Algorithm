#include<vector>

using namespace std;



class Solution {
	/*
	70. ��¥��
	������������¥�ݡ���Ҫ n ������ܵ���¥����

	ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
	*/
public:
	/*
	Times:O(n)
	Space:O(n)
	��̬�滮
	*/
	int climbStairs(int n) {
		vector<int> f(n + 2);
		f[1] = 1, f[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};