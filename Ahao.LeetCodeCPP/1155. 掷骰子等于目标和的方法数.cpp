#include<vector>
#include<string>

using namespace std;


/*
1155. �����ӵ���Ŀ��͵ķ�����

������ n ��һ�������ӣ�ÿ�������϶��� k ���棬�ֱ���Ϊ 1 �� k ��

������������ n ,  k �� target �����ؿ��ܵķ�ʽ(���ܹ� kn �ַ�ʽ��)�������ӵ�������ʹ���泯�ϵ�����֮�͵��� target ��

�𰸿��ܴܺ�����Ҫ�� 109 + 7 ȡģ ��
*/

class Solution {
public:
	int numRollsToTarget(int n, int k, int target) {
		vector<vector<int>> f(n + 1, vector<int>(target + 1));
		f[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= target; ++j) {
				for (int x = 1; x <= k; ++x) {
					if (j - x >= 0) {
						f[i][j] = (f[i][j] + f[i - 1][j - x]) % mod;
					}
				}
			}
		}
		return f[n][target];
	}

private:
	static constexpr int mod = 1000000007;
};



class Solution {
public:
	int numRollsToTarget(int n, int k, int target) {
		vector<int> f(target + 1);
		f[0] = 1;
		for (int i = 1; i <= n; ++i) {
			vector<int> g(target + 1);
			for (int j = 0; j <= target; ++j) {
				for (int x = 1; x <= k; ++x) {
					if (j - x >= 0) {
						g[j] = (g[j] + f[j - x]) % mod;
					}
				}
			}
			f = move(g);
		}
		return f[target];
	}

private:
	static constexpr int mod = 1000000007;
};



class Solution {
public:
	int numRollsToTarget(int n, int k, int target) {
		vector<int> f(target + 1);
		f[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = target; j >= 0; --j) {
				f[j] = 0;
				for (int x = 1; x <= k; ++x) {
					if (j - x >= 0) {
						f[j] = (f[j] + f[j - x]) % mod;
					}
				}
			}
		}
		return f[target];
	}

private:
	static constexpr int mod = 1000000007;
};

