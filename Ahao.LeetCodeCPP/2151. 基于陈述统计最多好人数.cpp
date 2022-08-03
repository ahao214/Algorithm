#include<vector>

using namespace std;


/*
2151. ���ڳ���ͳ����������
��Ϸ�д������ֽ�ɫ��

���ˣ��ý�ɫֻ˵�滰��
���ˣ��ý�ɫ����˵�滰��Ҳ����˵�ٻ���
����һ���±�� 0 ��ʼ�Ķ�ά�������� statements ����СΪ n x n ����ʾ n ����ҶԱ˴˽�ɫ�ĳ�����������˵��statements[i][j] ����������ֵ֮һ��

0 ��ʾ i �ĳ�����Ϊ j �� ���� ��
1 ��ʾ i �ĳ�����Ϊ j �� ���� ��
2 ��ʾ i û�ж� j ����������
���⣬��Ҳ�����Լ����г�������ʽ�ϣ������� 0 <= i < n ������ statements[i][i] = 2 ��

������ n ����ҵĳ��������ؿ�����Ϊ�� ���� �� ��� ��Ŀ��
*/
class Solution {
public:
	int maximumGood(vector<vector<int>>& statements) {
		int n = statements.size();

		int res = 0;
		for (int i = 0; i < 1 << n; i++)
		{
			bool flag = true;
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (statements[j][k] == 2)continue;
					if (i >> j & 1)
					{
						if ((i >> k & 1) != statements[j][k])
							flag = false;
					}
				}
			}
			if (flag)
			{
				int s = 0;
				for (int j = 0; j < n; j++)
					s += i >> j & 1;
				res = max(res, s);
			}
		}
		return res;
	}
};