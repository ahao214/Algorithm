#include<vector>
#include <functional>
#include<unordered_map>

using namespace std;

/*
1349. 参加考试的最大学生数

给你一个 m * n 的矩阵 seats 表示教室中的座位分布。如果座位是坏的（不可用），就用 '#' 表示；否则，用 '.' 表示。

学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。请你计算并返回该考场可以容纳的同时参加考试且无法作弊的 最大 学生人数。

学生必须坐在状况良好的座位上。
*/

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        unordered_map<int, int> memo;

        auto isSingleRowCompliant = [&](int status, int row) -> bool {
            for (int j = 0; j < n; j++) {
                if ((status >> j) & 1) {
                    if (seats[row][j] == '#') {
                        return false;
                    }
                    if (j > 0 && ((status >> (j - 1)) & 1)) {
                        return false;
                    }
                }
            }
            return true;
            };

        auto isCrossRowsCompliant = [&](int status, int upperRowStatus) -> bool {
            for (int j = 0; j < n; j++) {
                if ((status >> j) & 1) {
                    if (j > 0 && ((upperRowStatus >> (j - 1)) & 1)) {
                        return false;
                    }
                    if (j < n - 1 && ((upperRowStatus >> (j + 1)) & 1)) {
                        return false;
                    }
                }
            }
            return true;
            };

        function<int(int, int)> dp = [&](int row, int status) -> int {
            int key = (row << n) + status;
            if (!memo.count(key)) {
                if (!isSingleRowCompliant(status, row)) {
                    memo[key] = INT_MIN;
                    return INT_MIN;
                }
                int students = __builtin_popcount(status);
                if (row == 0) {
                    memo[key] = students;
                    return students;
                }
                int mx = 0;
                for (int upperRowStatus = 0; upperRowStatus < 1 << n; upperRowStatus++) {
                    if (isCrossRowsCompliant(status, upperRowStatus)) {
                        mx = max(mx, dp(row - 1, upperRowStatus));
                    }
                }
                memo[key] = students + mx;
            }
            return memo[key];
            };

        int mx = 0;
        for (int i = 0; i < (1 << n); i++) {
            mx = max(mx, dp(m - 1, i));
        }
        return mx;
    }
};

