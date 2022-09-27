#include<vector>
#include<string>

using namespace std;





/*
1771. �������й��������Ĵ��ĳ���
���������ַ��� word1 �� word2 �����㰴������������һ���ַ�����

�� word1 ��ѡ��ĳ�� �ǿ� ������ subsequence1 ��
�� word2 ��ѡ��ĳ�� �ǿ� ������ subsequence2 ��
�������������� subsequence1 + subsequence2 ���õ��ַ�����
���ؿɰ��������������� ���Ĵ� �� ���� ������޷�������Ĵ������� 0 ��

�ַ��� s ��һ�� ������ ��ͨ���� s ��ɾ��һЩ��Ҳ���ܲ�ɾ�����ַ��������������ַ���˳�����ɵ��ַ�����

���Ĵ� �����Ŷ��ͷ��Ŷ����һ�µ��ַ�����
*/

const int N = 1010;
int f1[N][N], f2[N][N], f3[N][N];
class Solution {
public:
	void work(string& s, int f[][N])
	{
		int n = s.size();
		for (int len = 1; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1;
				if (len == 1) f[i][j] = 1;
				else
				{
					f[i][j] = max(f[i + 1][j], f[i][j - 1]);
					if (s[i] == s[j])
						f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
				}
			}
		}
	}

	int longestPalindrome(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		reverse(word2.begin(), word2.end());
		memset(f1, 0, sizeof f1);
		memset(f2, 0, sizeof f2);
		memset(f3, 0, sizeof f3);
		word1 = ' ' + word1, word2 = ' ' + word2;
		work(word1, f2), work(word2, f3);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				f1[i][j] = max(f1[i - 1][j], f1[i][j - 1]);
				if (word1[i] == word2[j])
					f1[i][j] = max(f1[i][j], f1[i - 1][j - 1] + 1);
			}
		}

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (f1[i][j])
					res = max(res, f1[i][j] * 2 + max(f2[i + 1][n], f3[j + 1][m]));
			}
		}
		return res;
	}
};
