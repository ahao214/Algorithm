#include<string>
#include<vector>
using namespace std;


/*
72. �༭����
������������ word1 �� word2�� �뷵�ؽ� word1 ת���� word2 ��ʹ�õ����ٲ�����  ��

����Զ�һ�����ʽ����������ֲ�����

����һ���ַ�
ɾ��һ���ַ�
�滻һ���ַ�
*/
class Solution {
public:
	/*
	Times:O(n*m)
	Space:O(n*m)
	n��word1�ĳ���
	m��word2�ĳ���
	*/
	int minDistance(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		word1 = ' ' + word1;
		word2 = ' ' + word2;
		vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));

		for (int i = 0; i <= n; i++)
			f[i][0] = i;
		for (int j = 0; j <= m; j++)
			f[0][j] = j;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				if (word1[i] == word2[j])
				{
					f[i][j] = f[i - 1][j - 1];
				}
				else
				{
					f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;
				}
		}
		return f[n][m];
	}
};


/*
72. �༭����
������������ word1 �� word2�� �뷵�ؽ� word1 ת���� word2 ��ʹ�õ����ٲ�����  ��

����Զ�һ�����ʽ����������ֲ�����

����һ���ַ�
ɾ��һ���ַ�
�滻һ���ַ�
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		vector<vector<int>> f(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++) f[i][0] = i;
		for (int i = 0; i <= m; i++) f[0][i] = i;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
				f[i][j] = min(f[i][j], f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
			}
		}
		return f[n][m];
	}
};