#include<vector>
#include <numeric>

using namespace std;



/*
1641. ͳ���ֵ���Ԫ���ַ�������Ŀ

����һ������ n���뷵�س���Ϊ n ������Ԫ�� (a, e, i, o, u) ����Ұ� �ֵ������� ���ַ���������

�ַ��� s �� �ֵ������� ��Ҫ���㣺����������Ч�� i��s[i] ����ĸ���е�λ�������� s[i+1] ��ͬ���� s[i+1] ֮ǰ��
*/
class Solution {
	int dp[51][5];
public:
	int countVowelStrings(int n) {
		for (int k = 0; k < 5; k++)
			dp[0][k] = 1;

		for (int i = 1; i < n; i++)
			for (int k = 0; k < 5; k++)
			{
				for (int j = 0; j <= k; j++)
					dp[i][k] += dp[i - 1][j];
			}
		int res = 0;
		for (int k = 0; k < 5; k++)
			res += dp[n - 1][k];
		return res;
	}
};


class Solution {
public:
	int countVowelStrings(int n) {
		return comb(n + 4, 4);
	}

	int comb(int n, int m)
	{
		long long cnt = 1;
		for (int i = 0; i < m; i++)
		{
			cnt *= n - i;
			cnt /= i + 1;
		}
		return cnt;
	}
};




//�������
class Solution {
public:
	int countVowelStrings(int n) {
		return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
	}
};


//��̬�滮
class Solution {
public:
	int countVowelStrings(int n) {
		vector<int> dp(5, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < 5; j++) {
				dp[j] += dp[j - 1];
			}
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};