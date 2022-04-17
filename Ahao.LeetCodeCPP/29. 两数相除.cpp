using namespace std;
#include<vector>;



class Solution {
	/*
	29. �������
	�������������������� dividend �ͳ��� divisor��
	�����������Ҫ��ʹ�ó˷��������� mod �������

	���ر����� dividend ���Գ��� divisor �õ����̡�

	���������Ľ��Ӧ����ȥ��truncate����С�����֣����磺truncate(8.345) = 8
	�Լ� truncate(-2.7335) = -2
	*/
public:
	int divide(int dividend, int divisor) {
		bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0);
		if (dividend > 0) dividend = -dividend;
		if (divisor > 0) divisor = -divisor;

		vector<pair<int, int>> exp;
		for (int i = divisor, j = -1; i >= dividend; i += i, j += j) {
			exp.push_back({ i,j });
			if (i < INT_MIN / 2) break;
		}

		int ans = 0;
		for (int i = exp.size() - 1; i >= 0; i--) {
			if (exp[i].first >= dividend) {
				ans += exp[i].second;
				dividend -= exp[i].first;
			}
		}

		if (sign) return ans;
		if (ans == INT_MIN) return INT_MAX;
		return -ans;
	}
};
