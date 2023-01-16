#include<vector>
#include <string>

using namespace std;




/*
2484. ͳ�ƻ�����������Ŀ
���������ַ��� s �����㷵�� s �г���Ϊ 5 �� ���������� ��Ŀ�����ڴ𰸿��ܴܺ����㽫�𰸶� 109 + 7 ȡ�� �󷵻ء�

��ʾ��

���һ���ַ�����ǰ����ʹӺ���ǰ����ͬ����ô���� �����ַ��� ��
��������һ���ַ�����ɾ�����ɸ��ַ��󣬲��ı��ַ�˳��ʣ���ַ����ɵ��ַ�����
*/

using LL = long long;
LL MOD = 1e9 + 7;
class Solution {
	LL dp1[10005][10][10];
	LL count1[10005][10];

	LL dp2[10005][10][10];
	LL count2[10005][10];
public:
	int countPalindromes(string s) {
		int n = s.size();
		s = "#" + s;

		for (int j = 0; j <= 9; j++) {
			LL sum = 0;
			for (int i = 1; i <= n; i++) {
				sum += (s[i] == '0' + j);
				count1[i][j] = sum;
			}
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					dp1[i][j][k] = dp1[i - 1][j][k];
					if (s[i] == '0' + k) {
						dp1[i][j][k] = (dp1[i][j][k] + count1[i - 1][j]) % MOD;
					}
				}
			}
		}


		for (int j = 0; j <= 9; j++) {
			LL sum = 0;
			for (int i = n; i >= 1; i--) {
				sum += (s[i] == '0' + j);
				count2[i][j] = sum;
			}
		}

		for (int i = n - 1; i >= 1; i--) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					dp2[i][j][k] = dp2[i + 1][j][k];
					if (s[i] == '0' + k) {
						dp2[i][j][k] = (dp2[i][j][k] + count2[i + 1][j]) % MOD;
					}
				}
			}
		}

		LL res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					res += dp1[i - 1][j][k] * dp2[i + 1][j][k] % MOD;
					res %= MOD;
				}
			}
		}
		return res;
	}
};