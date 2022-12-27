#include <unordered_set>
using namespace std;


class Solution {
	bool isPrime(int x) {
		if (x < 2) {
			return false;
		}
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}

public:
	int countPrimeSetBits(int left, int right) {
		int ans = 0;
		for (int x = left; x <= right; ++x) {
			if (isPrime(__builtin_popcount(x))) {
				++ans;
			}
		}
		return ans;
	}

	//�ж������Ż�
	int countPrimeSetBits2(int left, int right) {
		int ans = 0;
		for (int x = left; x <= right; ++x) {
			if ((1 << __builtin_popcount(x)) & 665772) {
				++ans;
			}
		}
		return ans;
	}
};


/*
762. �����Ʊ�ʾ��������������λ
������������L��R ���ҵ�������[L, R]��Χ�ڣ�������λλ��Ϊ����������������

��ע�⣬������λ��������Ʊ�ʾ��1�ĸ�����
���� 21 �Ķ����Ʊ�ʾ10101��3��������λ�����У�1 ������������

ʾ�� 1:
*/
class Solution {
public:
	int countPrimeSetBits(int left, int right) {
		unordered_set<int> primes({ 2,3,5,7,11,13,17,19 });

		int res = 0;
		for (int i = left; i <= right; i++) {
			int s = 0;
			for (int k = i; k; k >>= 1)
				s += k & 1;
			if (primes.count(s))
				res++;
		}
		return res;
	}
};
