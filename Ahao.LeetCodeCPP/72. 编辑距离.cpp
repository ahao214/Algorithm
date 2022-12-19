#include<string>
#include<vector>
using namespace std;


/*
72. 编辑距离
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
*/
class Solution {
public:
	/*
	Times:O(n*m)
	Space:O(n*m)
	n是word1的长度
	m是word2的长度
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
72. 编辑距离
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
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