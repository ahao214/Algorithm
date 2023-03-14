#include<vector>
#include <string>

using namespace std;


/*
664. ��ֵĴ�ӡ��
��̨��ֵĴ�ӡ����������������Ҫ��

��ӡ��ÿ��ֻ�ܴ�ӡ�� ͬһ���ַ� ��ɵ����С�
ÿ�ο����ڴ���ʼ������������λ�ô�ӡ���ַ������һḲ�ǵ�ԭ�����е��ַ���
����һ���ַ��� s ����������Ǽ��������ӡ����ӡ����Ҫ�����ٴ�ӡ������
*/
class Solution {
public:
	int strangePrinter(string s) {
		int n = s.size();
		vector<vector<int>> f(n + 2, vector<int>(n + 2));
		for (int len = 1; len <= n; len++)
		{
			for (int l = 1; l + len - 1 <= n; l++)
			{
				int r = l + len - 1;
				f[l][r] = f[l + 1][r] + 1;
				for (int k = l + 1; k <= r; k++)
					if (s[k - 1] == s[l - 1])
					{
						f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r]);
					}
			}
		}
		return f[1][n];
	}
};





/*
664. ��ֵĴ�ӡ��

��̨��ֵĴ�ӡ����������������Ҫ��

��ӡ��ÿ��ֻ�ܴ�ӡ�� ͬһ���ַ� ��ɵ����С�
ÿ�ο����ڴ���ʼ������������λ�ô�ӡ���ַ������һḲ�ǵ�ԭ�����е��ַ���
����һ���ַ��� s ����������Ǽ��������ӡ����ӡ����Ҫ�����ٴ�ӡ������
*/
class Solution {
public:
	int strangePrinter(string s) {
		int n = s.size();
		if (!n) return 0;
		vector<vector<int>> f(n + 1, vector<int>(n + 1));
		for (int len = 1; len <= n; len++)
		{
			for (int i = 0; i + len - 1 < n; i++)
			{
				int j = i + len - 1;
				f[i][j] = 1 + f[i + 1][j];
				for (int k = i + 1; k <= j; k++)
					if (s[i] == s[k])
						f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j]);
			}
		}
		return f[0][n - 1];
	}
};