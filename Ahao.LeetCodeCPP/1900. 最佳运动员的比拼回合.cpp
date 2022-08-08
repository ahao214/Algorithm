#include<vector>

using namespace std;



/*
1900. ����˶�Ա�ı�ƴ�غ�
n ���˶�Ա����һ���������������˶�Ավ��һ�ţ������� �ʼ�� վλ�� 1 �� n ��ţ��˶�Ա 1 ����һ���еĵ�һ���˶�Ա���˶�Ա 2 �ǵڶ����˶�Ա���������ƣ���

�������ɶ���غ���ɣ��ӻغ� 1 ��ʼ����ÿһ�غ��У���һ�Ŵ�ǰ�������ĵ� i ���˶�Ա��Ҫ��Ӻ���ǰ���ĵ� i ���˶�Ա��ƴ����ʤ�߽��������һ�غϡ������ǰ�غ����˶�Ա��ĿΪ��������ô�м���λ�˶�Ա���ֿս�����һ�غϡ�

���磬��ǰ�غ��У��˶�Ա 1, 2, 4, 6, 7 վ��һ��
�˶�Ա 1 ��Ҫ���˶�Ա 7 ��ƴ
�˶�Ա 2 ��Ҫ���˶�Ա 6 ��ƴ
�˶�Ա 4 �ֿս�����һ�غ�
ÿ�غϽ����󣬻�ʤ�߽�������ʼ��������ǵ�ԭʼ˳�����������ų�һ�š�

���Ϊ firstPlayer �� secondPlayer ���˶�Ա�Ǳ����������е�����˶�Ա�������ǿ�ʼ��ƴ֮ǰ����ȫ����սʤ�κ������˶�Ա�����������������˶�Ա���б�ƴʱ����������һ�����л�ʤ�Ŀ��ܣ��������� �ö� ˭����һ�غϵĻ�ʤ�ߡ�

������������ n��firstPlayer �� secondPlayer ������һ��������ֵ��ɵ��������飬�ֱ��ʾ��λ����˶�Ա�ڱ����������б�ƴ�� ���� �غ����� ���� �غ�����
*/


const int N = 30;
bool f[N][N][N];

class Solution {
public:
	vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
		memset(f, 0, sizeof f);
		f[n][firstPlayer - 1][n - secondPlayer] = true;
		for (int k = n; k > 1; k = (k + 1) / 2)
		{
			for (int x = 0; x <= n; x++)
			{
				for (int y = 0; y <= n; y++)
				{
					if (f[k][x][y])
					{
						int m = (k + 1) / 2, m2 = k - m;
						if (y >= m2)
						{
							int z = k - x - y - 2;
							for (int i = 0; i <= x; i++)
								for (int j = 0; j <= z; j++)
									f[m][i][j + x - i + y - m2] = true;
						}
						else if (x >= m2)
						{
							int z = k - x - y - 2;
							for (int i = 0; i <= y; i++)
								for (int j = 0; j <= z; j++)
									f[m][j + y - i + x - m2][i] = true;
						}
						else if (x < y)
						{
							int z = y - x - 1;
							for (int i = 0; i <= x; i++)
								for (int j = 0; j <= z; j++)
									f[m][i][x - i + j] = true;
						}
						else if (x > y)
						{
							int z = x - y - 1;
							for (int i = 0; i <= y; i++)
								for (int j = 0; j <= z; j++)
									f[m][y - i + j][i] = true;

						}
					}
				}
			}
		}
		int r1 = INT_MAX, r2 = INT_MIN;
		for (int k = n, t = 1; k > 1; k = (k + 1) / 2, t++)
		{
			for (int i = 0; i <= n; i++)
			{
				if (f[k][i][i])
				{
					r1 = min(r1, t);
					r2 = max(r2, t);
				}
			}
		}
		return { r1,r2 };
	}

};




