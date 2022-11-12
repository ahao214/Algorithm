#include<vector>

using namespace std;

/*
790. ����ŵ������ŵƽ��

�е�

��������״�Ĵ�ש��һ���� 2 x 1 �Ķ���ŵ�Σ���һ�������� "L" ������ŵ�Ρ�������״��������ת��



�������� n �����ؿ���ƽ�� 2 x n �����ķ��������������ض� 109 + 7 ȡģ ��ֵ��

ƽ��ָ����ÿ�������ζ������д�ש���ǡ�����ƽ�̲�ͬ�����ҽ�����������ĸ������ϵ����ڵ�Ԫ�е�������ʹ��ǡ����һ��ƽ����һ����שռ�����������Ρ�


ʾ�� 1:

����: n = 3
���: 5
����: ���ֲ�ͬ�ķ���������ʾ��
ʾ�� 2:

����: n = 1
���: 1


��ʾ��

1 <= n <= 1000
*/

/*
��̬�滮
*/
const long long mod = 1e9 + 7;
class Solution {
public:
	int numTilings(int n) {
		vector<vector<long long>> dp(n + 1, vector<long long>(4));
		dp[0][3] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][3];
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
			dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
			dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
		}
		return dp[n][3];
	}
};


/*
���������
*/
const long long mod = 1e9 + 7;
class Solution {
public:
	vector<vector<long long>> mulMatrix(const vector<vector<long long>>& m1, const vector<vector<long long>>& m2) {
		int n1 = m1.size(), n2 = m2.size(), n3 = m2[0].size();
		vector<vector<long long>> res(n1, vector<long long>(n3));
		for (int i = 0; i < n1; i++) {
			for (int k = 0; k < n3; k++) {
				for (int j = 0; j < n2; j++) {
					res[i][k] = (res[i][k] + m1[i][j] * m2[j][k]) % mod;
				}
			}
		}
		return res;
	}

	int numTilings(int n) {
		vector<vector<long long>> mat = {
			{0, 0, 0, 1},
			{1, 0, 1, 0},
			{1, 1, 0, 0},
			{1, 1, 1, 1}
		};
		vector<vector<long long>> matn = {
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
		};
		while (n) {
			if (n & 1) {
				matn = mulMatrix(matn, mat);
			}
			mat = mulMatrix(mat, mat);
			n >>= 1;
		}
		return matn[3][3];
	}
};
