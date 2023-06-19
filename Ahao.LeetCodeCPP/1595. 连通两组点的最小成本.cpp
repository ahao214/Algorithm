#include<vector>

using namespace std;


/*
1595. ��ͨ��������С�ɱ�

��������㣬���е�һ������ size1 ���㣬�ڶ������� size2 ���㣬�� size1 >= size2 ��

�������������ӳɱ� cost �ɴ�СΪ size1 x size2 ������������� cost[i][j] �ǵ�һ���еĵ� i �͵ڶ����еĵ� j �����ӳɱ�������������е�ÿ���㶼����һ���е�һ�����������ӣ���������������ͨ�ġ�����֮����һ���е�ÿ�������������ڶ����е�һ�������ӣ��ҵڶ����е�ÿ��������������һ���е�һ�������ӡ�

������ͨ������������С�ɱ���
*/

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int size1 = cost.size(), size2 = cost[0].size(), m = 1 << size2;
        vector<vector<int>> dp(size1 + 1, vector<int>(m, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= size1; i++) {
            for (int s = 0; s < m; s++) {
                for (int k = 0; k < size2; k++) {
                    if ((s & (1 << k)) == 0) {
                        continue;
                    }
                    dp[i][s] = min(dp[i][s], dp[i][s ^ (1 << k)] + cost[i - 1][k]);
                    dp[i][s] = min(dp[i][s], dp[i - 1][s] + cost[i - 1][k]);
                    dp[i][s] = min(dp[i][s], dp[i - 1][s ^ (1 << k)] + cost[i - 1][k]);
                }
            }
        }
        return dp[size1][m - 1];
    }
};
