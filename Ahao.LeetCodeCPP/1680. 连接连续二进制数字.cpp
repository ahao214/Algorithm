#include<vector>

using namespace std;



/*
1680. ������������������
����һ������ n �����㽫 1 �� n �Ķ����Ʊ�ʾ�������������������ӽ����Ӧ�� ʮ���� ���ֶ� 10^9 + 7 ȡ��Ľ����
*/
class Solution {
public:
	int getLen(int x)
	{
		int res = 0;
		while (x) res++, x >>= 1;
		return res;
	}

	int concatenatedBinary(int n) {
		long long res = 0, mod = 1e9 + 7;
		for (int i = 1; i <= n; i++)
			(res = (res << getLen(i)) + i) %= mod;
		return res;
	}

	int concatenatedBinary(int n) {
		long long res = 0, mod = 1e9 + 7;
		vector<int> g(n + 1);
		for (int i = 1; i <= n; i++)
		{
			g[i] = g[i / 2] + 1;
			(res = (res << g[i]) + i) %= mod;
		}
		return res;
	}
};