#include<vector>

using namespace std;


/*
1808. �����ӵ������Ŀ
����һ�������� primeFactors ������Ҫ����һ�������� n ������������������

n ����������������Ҫ�����ظ������������Ŀ ������ primeFactors ����
n �����ӵ���Ŀ��󻯡���� n ��һ�����ӿ��Ա� n ��ÿһ�����������������ǳ���������� ������ ���ȷ�˵����� n = 12 ����ô����������Ϊ [2,2,3] ����ô 6 �� 12 �Ǻ����ӣ��� 3 �� 4 ���ǡ�
���㷵�� n �ĺ����ӵ���Ŀ�����ڴ𰸿��ܻ�ܴ��뷵�ش𰸶� 109 + 7 ȡ�� �Ľ����

��ע�⣬һ�������Ķ����Ǵ��� 1 ���Ҳ��ܱ��ֽ�Ϊ����С�ڸ�������Ȼ����ˡ�һ���� n ���������ǽ� n �ֽ�Ϊ���ɸ������ӣ������ǵĳ˻�Ϊ n ��
*/
typedef long long LL;
const int MOD = 1e9 + 7;
class Solution {
public:
	int qmi(int a, int b)
	{
		int res = 1;
		while (b)
		{
			if (b & 1) res = (LL)res * a % MOD;
			a = (LL)a * a % MOD;
			b >>= 1;
		}
		return res;
	}

	int maxNiceDivisors(int primeFactors) {
		if (primeFactors <= 3) return primeFactors;
		if (primeFactors % 3 == 0) return qmi(3, primeFactors / 3);
		if (primeFactors % 3 == 1)
			return (LL)qmi(3, (primeFactors - 4) / 3) * 4 % MOD;
		return (LL)qmi(3, (primeFactors - 2) / 3) * 2 % MOD;
	}
};