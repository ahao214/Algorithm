#include<vector>
#include<string>

using namespace std;

/*
1444. �������ķ�����

����һ�� rows x cols ��С�ľ���������һ������ k �����ΰ��������ַ��� 'A' ����ʾƻ������ '.' ����ʾ�հ׸��ӣ�������Ҫ������ k-1 �Σ��õ� k ���������͸����ˡ�

��������ÿһ������Ҫѡ������ֱ����ˮƽ�����У����ھ��εı߽���ѡһ���е�λ�ã�������һ��Ϊ���������ֱ������������ô��Ҫ����ߵĲ����͸�һ���ˣ����ˮƽ���У���ô��Ҫ������Ĳ����͸�һ���ˡ����������һ������Ҫ��ʣ������һ���͸����һ���ˡ�

���㷵��ȷ��ÿһ���������� ���� һ��ƻ���������������������ڴ𰸿����Ǹ��ܴ�����֣����㷵������ 10^9 + 7 ȡ��Ľ����
*/


class Solution {
public:
	int ways(vector<string>& pizza, int k) {
		int m = pizza.size(), n = pizza[0].size(), mod = 1e9 + 7;
		vector<vector<int>> apples(m + 1, vector<int>(n + 1));
		vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

		// Ԥ����
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
				dp[1][i][j] = apples[i][j] > 0;
			}
		}

		for (int ki = 2; ki <= k; ki++) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					// ˮƽ������
					for (int i2 = i + 1; i2 < m; i2++) {
						if (apples[i][j] > apples[i2][j]) {
							dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
						}
					}
					// ��ֱ������
					for (int j2 = j + 1; j2 < n; j2++) {
						if (apples[i][j] > apples[i][j2]) {
							dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
						}
					}
				}
			}
		}
		return dp[k][0][0];
	}
};
