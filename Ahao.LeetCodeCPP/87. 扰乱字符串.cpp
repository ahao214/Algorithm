#include<vector>
#include<string>

using namespace std;


class Solution {
	/*
	87. �����ַ���
	ʹ�������������㷨���������ַ��� s �õ��ַ��� t ��
	����ַ����ĳ���Ϊ 1 ���㷨ֹͣ
	����ַ����ĳ��� > 1 ��ִ���������裺
	��һ������±괦���ַ����ָ�������ǿյ����ַ��������������֪�ַ��� s ������Խ���ֳ��������ַ��� x �� y �������� s = x + y ��
	��� ������Ҫ�������������ַ���������Ҫ���������������ַ�����˳�򲻱䡹��������ִ����һ����֮��s ������ s = x + y ���� s = y + x ��
	�� x �� y ���������ַ����ϼ����Ӳ��� 1 ��ʼ�ݹ�ִ�д��㷨��
	�������� ������� ���ַ��� s1 �� s2���ж� s2 �Ƿ��� s1 �������ַ���������ǣ����� true �����򣬷��� false ��
	*/
public:
	/*
	Times:O(n^4)
	Space:O(n^3)
	*/
	bool isScramble(string s1, string s2) {
		int n = s1.size();
		vector<vector<vector<bool>>>f(n + 1, vector<vector<bool>>(n + 1, vector<bool>(n + 1)));

		for (int k = 1; k <= n; k++)
		{
			for (int i = 0; i + k - 1 < n; i++)
			{
				for (int j = 0; j + k - 1 < n; j++)
				{
					if (k == 1)
					{
						f[i][j][k] = s1[i] == s2[j];
						continue;
					}
					for (int u = 1; u < k; u++)
					{
						bool o1 = f[i][j][u] && f[i + u][j + u][k - u];
						bool o2 = f[i][j + k - u][u] && f[i + u][j][k - u];
						if (o1 || o2)
						{
							f[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
		return f[0][0][n];
	}
};
