#include<vector>
#include <string>

using namespace std;




/*
2472. ���ص��������ַ����������Ŀ

����һ���ַ��� s ��һ�������� k ��

���ַ��� s ��ѡ��һ���������������� ���ص� �����ַ�����

ÿ�����ַ����ĳ��� ���� Ϊ k ��
ÿ�����ַ�����һ�� ���Ĵ� ��
�������ŷ�������ѡ������ַ����� ��� ��Ŀ��

���ַ��� ���ַ�����һ���������ַ����С�
*/
class Solution {
public:
	int maxPalindromes(string s, int k) {
		int n = s.size();
		vector<vector<int>>isPalin(n, vector<int>(n));

		for (int i = 0; i < n; i++) {
			isPalin[i][i] = true;
		}
		for (int i = 0; i + 1 < n; i++) {
			isPalin[i][i + 1] = (s[i] == s[i + 1]);
		}

		for (int len = 3; len <= n; len++) {
			for (int i = 0; i + len - 1 < n; i++) {
				int j = i + len - 1;
				if (s[i] == s[j])
					isPalin[i][j] = isPalin[i + 1][j - 1];
			}
		}

		vector<int>dp(n);
		for (int i = k - 1; i < n; i++) {
			dp[i] = (i == 0 ? 0 : dp[i - 1]);
			for (int j = 0; j <= i - k + 1; j++) {
				if (isPalin[j][i])
					dp[i] = max(dp[i], (j == 0 ? 0 : dp[j - 1]) + 1);
			}
		}
		return dp[n - 1];
	}
};
