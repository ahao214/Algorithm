#include<vector>

using namespace std;


/*
1510. ʯ����Ϸ IV
Alice �� Bob ������������һ����Ϸ��Alice ���֡�

һ��ʼ���� n ��ʯ�Ӷ���һ��ÿ�����������������ڲ�������ҿ��Դ�ʯ�Ӷ������� ���� ���� ƽ���� ��ʯ�ӡ�

���ʯ�Ӷ���û��ʯ���ˣ����޷���������������Ϸ��

���������� n ������֪�����˶���ȡ���Ų��ԡ���� Alice ��Ӯ�ñ�������ô���� True �����򷵻� False ��
*/
class Solution {
public:
	bool winnerSquareGame(int n) {
		vector<bool> f(n + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j * j <= i; j++)
			{
				if (f[i - j * j] == false)
				{
					f[i] = true;
					break;
				}
			}
		}
		return f[n];
	}
};