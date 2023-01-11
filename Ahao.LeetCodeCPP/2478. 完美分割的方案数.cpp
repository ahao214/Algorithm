#include<vector>
#include<string>


using namespace std;



/*
2478. �����ָ�ķ�����
����һ���ַ��� s ��ÿ���ַ������� '1' �� '9' ���ٸ����������� k �� minLength ��

����� s �ķָ�����������������ô������Ϊ����һ�� ���� �ָ

s ���ֳ� k �λ����ཻ�����ַ�����
ÿ�����ַ������ȶ� ���� Ϊ minLength ��
ÿ�����ַ����ĵ�һ���ַ�����һ�� ���� ���֣����һ���ַ�����һ�� ������ ���֡���������Ϊ '2' ��'3' ��'5' �� '7' ��ʣ�µĶ��Ƿ��������֡�
���㷵�� s �� ���� �ָ���Ŀ�����ڴ𰸿��ܴܺ��뷵�ش𰸶� 109 + 7 ȡ�� ��Ľ����

һ�� ���ַ��� ���ַ�����һ�������ַ������С�
*/
using LL = long long;
class Solution {
	LL dp[1005][1005];
	LL M = 1e9 + 7;
public:
	int beautifulPartitions(string s, int k, int minLength) {
		int n = s.size();
		s = "#" + s;

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (isprime(s[i])) {
					dp[i][j] = 0;
					continue;
				}
				for (int k = j; k + minLength - 1 <= i; k++) {
					if (isprime(s[k]))
					{
						dp[i][j] += dp[k - 1][j - 1];
						dp[i][j] %= M;
					}
				}
			}
		}
		return dp[n][k];
	}

	bool isprime(char ch) {
		return ch == '2' || ch == '3' || ch == '5' || ch == '7';
	}
};


using LL = long long;
class Solution {
	LL dp[1005][1005];
	LL M = 1e9 + 7;
public:
	int beautifulPartitions(string s, int k, int minLength) {
		int n = s.size();
		s = "#" + s;

		dp[0][0] = 1;
		for (int j = 1; j <= k; j++) {
			LL presum = 0;
			for (int i = 1; i <= n; i++) {
				if (i - minLength + 1 >= 1 && isprime(s[i - minLength + 1]) && !isprime(s[i - minLength])) {
					presum += dp[i - minLength][j - 1];
					presum %= M;
				}
				if (!isprime(s[i]))
				{
					dp[i][j] = presum % M;
				}
			}
		}
		return dp[n][k];
	}

	bool isprime(char ch) {
		return ch == '2' || ch == '3' || ch == '5' || ch == '7';
	}
};
