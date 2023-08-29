#include<vector>
#include <queue>
#include <unordered_set>

using namespace std;


/*
1654. 到家的最少跳跃次数

有一只跳蚤的家在数轴上的位置 x 处。请你帮助它从位置 0 出发，到达它的家。

跳蚤跳跃的规则如下：

它可以 往前 跳恰好 a 个位置（即往右跳）。
它可以 往后 跳恰好 b 个位置（即往左跳）。
它不能 连续 往后跳 2 次。
它不能跳到任何 forbidden 数组中的位置。
跳蚤可以往前跳 超过 它的家的位置，但是它 不能跳到负整数 的位置。

给你一个整数数组 forbidden ，其中 forbidden[i] 是跳蚤不能跳到的位置，同时给你整数 a， b 和 x ，请你返回跳蚤到家的最少跳跃次数。如果没有恰好到达 x 的可行方案，请你返回 -1 。

*/
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // 最远距离 bound = max(F + a + b, x + b)
        int F = *max_element(forbidden.begin(), forbidden.end()), bound = max(F + a + b, x + b);

        int ban[bound + 1];
        memset(ban, 0, sizeof(ban));
        for (int f : forbidden) {
            ban[f] = 1;
        }

        int dist[bound + 1][2]; // dist[i][0] - 上一次前跳, dist[i][1] - 上一次后跳
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        queue<pair<int, int>> q({ {0, 0} });
        while (q.size()) {
            auto [i, pre;] = q.front(); q.pop();
            if (i == x) {
                return dist[i][pre];
            }
            if (pre == 0 && i - b >= 0 && !ban[i - b] && dist[i][pre] + 1 < dist[i - b][1]) {
                dist[i - b][1] = dist[i][pre] + 1;
                q.emplace(i - b, 1);
            }
            if (i + a <= bound && !ban[i + a] && dist[i][pre] + 1 < dist[i + a][0]) {
                dist[i + a][0] = dist[i][pre] + 1;
                q.emplace(i + a, 0);
            }
        }

        return -1;
    }
};


class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<tuple<int, int, int>> q;
        unordered_set<int> visited;
        q.emplace(0, 1, 0);
        visited.emplace(0);
        int lower = 0, upper = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) + b;
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
        while (!q.empty()) {
            auto [position, direction, step] = q.front();
            q.pop();
            if (position == x) {
                return step;
            }
            int nextPosition = position + a;
            int nextDirection = 1;
            if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition)) {
                visited.emplace(nextPosition * nextDirection);
                q.emplace(nextPosition, nextDirection, step + 1);
            }
            if (direction == 1) {
                nextPosition = position - b;
                nextDirection = -1;
                if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition)) {
                    visited.emplace(nextPosition * nextDirection);
                    q.emplace(nextPosition, nextDirection, step + 1);
                }
            }
        }
        return -1;
    }
};
