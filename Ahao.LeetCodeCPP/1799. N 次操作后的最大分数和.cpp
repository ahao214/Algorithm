#include<vector>

using namespace std;


/*
1799. N �β��������������
���� nums ������һ����СΪ 2 * n �����������顣�������������ִ�� n �β�����

�ڵ� i �β���ʱ��������Ŵ� 1 ��ʼ��������Ҫ��

ѡ������Ԫ�� x �� y ��
��÷��� i * gcd(x, y) ��
�� x �� y �� nums ��ɾ����
���㷵�� n �β��������ܻ�õķ��������Ϊ���١�

���� gcd(x, y) �� x �� y �����Լ����
*/
class Solution {
public:
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}
	int maxScore(vector<int>& nums) {
		int n = nums.size();
		vector<int> f(1 << n);
		for (int i = 0; i < 1 << n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (!(i >> j & 1))
					cnt++;
			}
			cnt = cnt / 2 + 1;
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
					for (int k = j + 1; k < n; k++)
						if (i >> k & 1)
							f[i] = max(f[i], f[i - (1 << j) - (1 << k)] + gcd(nums[j], nums[k]) * cnt);
			}
		}
		return f[(1 << n) - 1];
	}
};


class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        vector<int> dp(1 << m, 0);
        vector<vector<int>> gcd_tmp(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                gcd_tmp[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int all = 1 << m;
        for (int s = 1; s < all; ++s) {
            int t = __builtin_popcount(s);
            if (t & 1) {
                continue;
            }
            for (int i = 0; i < m; ++i) {
                if ((s >> i) & 1) {
                    for (int j = i + 1; j < m; ++j) {
                        if ((s >> j) & 1) {
                            dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
                        }
                    }
                }
            }
        }
        return dp[all - 1];
    }
};
