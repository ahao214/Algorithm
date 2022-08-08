#include<vector>
#include<string>

using namespace std;



/*
1888. ʹ�������ַ����ַ���������ٷ�ת����
����һ���������ַ��� s ������԰�����˳��ִ���������ֲ�������Σ�

���� 1 ��ɾ�� �ַ��� s �ĵ�һ���ַ������� ��� ���ַ�����β��
���� 2 ��ѡ�� �ַ��� s ������һ���ַ��������ַ� ��ת ��Ҳ�������ֵΪ '0' ����ת�õ� '1' ����֮��Ȼ��
���㷵��ʹ s ��� ���� �ַ�����ǰ���£� ���� 2 �� ���� �������� ��

���ǳ�һ���ַ����� ���� �ģ���Ҫ�������������ַ�����ͬ��

�ȷ�˵���ַ��� "010" �� "1010" ���ǽ���ģ������ַ��� "0100" ���ǡ�
*/
class Solution {
public:
	int minFlips(string s) {
		int n = s.size();
		vector<int> left[2], right[2];
		left[0] = left[1] = right[0] = right[1] = vector<int>(n);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0, c = 0, k = i; j < n; j++, k ^= 1)
			{
				if (k != s[j] - '0')c++;
				left[i][j] = c;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = n - 1, c = 0, k = i; j >= 0; j--, k ^= 1)
			{
				if (k != s[j] - '0') c++;
				right[i][j] = c;
			}
		}

		if (n % 2 == 0)
			return min(left[0][n - 1], left[1][n - 1]);
		else
		{
			int res = min(left[0][n - 1], left[1][n - 1]);
			for (int i = 0; i + 1 < n; i++)
			{
				res = min(res, left[0][i] + right[1][i + 1]);
				res = min(res, left[1][i] + right[0][i + 1]);
			}
			return res;
		}
	}

};
