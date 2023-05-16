#include<vector>

using namespace std;

/*
1335. �����ƻ�������Ѷ�

����Ҫ�ƶ�һ�� d ��Ĺ����ƻ�������֮�����������Ҫ��ִ�е� i �������������ȫ�� j ����� 0 <= j < i����

��ÿ�� ���� ��Ҫ���һ�����񡣹����ƻ������Ѷ����� d ��ÿһ����Ѷ�֮�ͣ���һ��Ĺ����Ѷ��ǵ���Ӧ����ɹ���������Ѷȡ�

����һ���������� jobDifficulty ��һ������ d���ֱ�������ѶȺ���Ҫ�ƻ����������� i ������Ѷ��� jobDifficulty[i]��

�������������ƻ��� ��С�Ѷ� ������޷��ƶ������ƻ����򷵻� -1 ��
*/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d + 1, vector<int>(n, 0x3f3f3f3f));
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            ma = max(ma, jobDifficulty[i]);
            dp[0][i] = ma;
        }
        for (int i = 1; i < d; ++i) {
            for (int j = i; j < n; ++j) {
                ma = 0;
                for (int k = j; k >= i; --k) {
                    ma = max(ma, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], ma + dp[i - 1][k - 1]);
                }
            }
        }
        return dp[d - 1][n - 1];
    }
};



class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<int> dp(n);
        for (int i = 0, j = 0; i < n; ++i) {
            j = max(j, jobDifficulty[i]);
            dp[i] = j;
        }
        for (int i = 1; i < d; ++i) {
            vector<int> ndp(n, 0x3f3f3f3f);
            for (int j = i; j < n; ++j) {
                int ma = 0;
                for (int k = j; k >= i; --k) {
                    ma = max(ma, jobDifficulty[k]);
                    ndp[j] = min(ndp[j], ma + dp[k - 1]);
                }
            }
            swap(ndp, dp);
        }
        return dp[n - 1];
    }
};
