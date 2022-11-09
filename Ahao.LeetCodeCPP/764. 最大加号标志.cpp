#include<vector>
#include <unordered_set>

using namespace std;

/*
764. ���Ӻű�־

�е�

�����ҵ
��һ�� n x n �ľ��� grid �У����������� mines �и�����Ԫ��Ϊ 0������ÿ��Ԫ�ض�Ϊ 1��mines[i] = [xi, yi]��ʾ grid[xi][yi] == 0

����  grid �а��� 1 ������ ����� �Ӻű�־�Ľ��� �����δ�ҵ��Ӻű�־���򷵻� 0 ��

һ�� k ���� 1 ��ɵ� ����Գơ��Ӻű�־ ������������ grid[r][c] == 1 ���Լ�4�����������ϡ����¡������������죬����Ϊ k-1���� 1 ��ɵıۡ�ע�⣬ֻ�мӺű�־����������Ҫ��Ϊ 1 ������������Ϊ 0 Ҳ����Ϊ 1 ��
*/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        unordered_set<int> banned;
        for (auto&& vec : mines) {
            banned.emplace(vec[0] * n + vec[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            /* left */
            for (int j = 0; j < n; j++) {
                if (banned.count(i * n + j)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            /* right */
            for (int j = n - 1; j >= 0; j--) {
                if (banned.count(i * n + j)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            /* up */
            for (int j = 0; j < n; j++) {
                if (banned.count(j * n + i)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
            }
            count = 0;
            /* down */
            for (int j = n - 1; j >= 0; j--) {
                if (banned.count(j * n + i)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
