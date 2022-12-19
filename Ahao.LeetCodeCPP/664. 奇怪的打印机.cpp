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