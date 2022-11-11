#include<vector>
#include <string>

using namespace std;



/*
1663. ���и�����ֵ����С�ַ���
Сд�ַ� �� ��ֵ ��������ĸ���е�λ�ã��� 1 ��ʼ������� a ����ֵΪ 1 ��b ����ֵΪ 2 ��c ����ֵΪ 3 ���Դ����ơ�

�ַ���������Сд�ַ���ɣ��ַ�������ֵ Ϊ���ַ�����ֵ֮�͡����磬�ַ��� "abe" ����ֵ���� 1 + 2 + 5 = 8 ��

������������ n �� k ������ ���� ���� n �� ��ֵ ���� k �� �ֵ�����С ���ַ�����

ע�⣬����ַ��� x ���ֵ�������λ�� y ֮ǰ������Ϊ x �ֵ���� y С�����������������

x �� y ��һ��ǰ׺��
��� i �� x[i] != y[i] �ĵ�һ��λ�ã��� x[i] ����ĸ���е�λ�ñ� y[i] ��ǰ��
*/
class Solution {
public:
	string getSmallestString(int n, int k) {
		string res;
		for (int i = 0, s = 0; i < n; i++)
		{
			for (int j = 1; j <= 26; j++)
			{
				int last = k - s - j, m = n - i - 1;
				if (last >= m && last <= m * 26)
				{
					res += j + 'a' - 1;
					s += j;
					break;
				}
			}
		}
		return res;
	}
};