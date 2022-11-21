#include<vector>

using namespace std;


/*
808. ����

�� A �� B �������� ������һ��ʼÿ�����͵����� n �����������ַ��������

�ṩ 100ml �� ��A �� 0ml �� ��B ��
�ṩ 75ml �� ��A �� 25ml �� ��B ��
�ṩ 50ml �� ��A �� 50ml �� ��B ��
�ṩ 25ml �� ��A �� 75ml �� ��B ��
�����ǰ��������ĳ��֮������û���ˡ�ÿ���غϣ����ǽ������ָ���ͬΪ 0.25 �Ĳ����н��з���ѡ���������ʣ�������������ĳ�β��������ǽ������ܷ��䡣���������͵�����������ʱ��ֹͣ������

ע�� �������ȷ��� 100 ml ��B �Ĳ�����

��Ҫ���ص�ֵ�� ��A �ȷ�����ĸ��� +  ��A����B ͬʱ������ĸ��� / 2������ֵ����ȷ�� 10-5 �ķ�Χ�ڽ�����Ϊ����ȷ�ġ�
*/


//��̬�滮
class Solution {
public:
    double soupServings(int n) {
        n = ceil((double)n / 25);
        if (n >= 179) {
            return 1.0;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1.0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] +
                    dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]) / 4.0;
            }
        }
        return dp[n][n];
    }
};


//���仯����
class Solution {
public:
    double soupServings(int n) {
        n = ceil((double)n / 25);
        if (n >= 179) {
            return 1.0;
        }
        memo = vector<vector<double>>(n + 1, vector<double>(n + 1));
        return dfs(n, n);
    }

    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        else if (a <= 0) {
            return 1;
        }
        else if (b <= 0) {
            return 0;
        }
        if (memo[a][b] > 0) {
            return memo[a][b];
        }
        memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
        return memo[a][b];
    }
private:
    vector<vector<double>> memo;
};
