#include<vector>

using namespace std;

/*
1335. 工作计划的最低难度

你需要制定一份 d 天的工作计划表。工作之间存在依赖，要想执行第 i 项工作，你必须完成全部 j 项工作（ 0 <= j < i）。

你每天 至少 需要完成一项任务。工作计划的总难度是这 d 天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大难度。

给你一个整数数组 jobDifficulty 和一个整数 d，分别代表工作难度和需要计划的天数。第 i 项工作的难度是 jobDifficulty[i]。

返回整个工作计划的 最小难度 。如果无法制定工作计划，则返回 -1 。
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
