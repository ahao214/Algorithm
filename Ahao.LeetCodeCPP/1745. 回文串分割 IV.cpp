#include<vector>
#include<string>

using namespace std;


/*
1745. ���Ĵ��ָ� IV
����һ���ַ��� s ��������Խ����ָ������ �ǿ� �������ַ�������ô���� true �����򷵻� false ��

��һ���ַ������Ŷ��ͷ��Ŷ���һģһ���ģ��ͳ���Ϊ �����ַ��� ��
*/
class Solution {
public:
	bool checkPartitioning(string s) {
		int n = s.size();
		vector<vector<bool>> f(n, vector<bool>(n));
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j) f[i][j] = true;
				else if (i + 1 == j) f[i][j] = s[i] == s[j];
				else f[i][j] = s[i] == s[j] && f[i + 1][j - 1];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j + 1 < n; j++)
			{
				if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1])
					return true;
			}
		}
		return false;
	}
};