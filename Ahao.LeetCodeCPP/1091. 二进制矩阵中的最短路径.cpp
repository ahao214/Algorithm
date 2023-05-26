#include<vector>
#include <queue>

using namespace std;

/*
1091. 二进制矩阵中的最短路径

难度：中等

给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。

二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：

路径途经的所有单元格都的值都是 0 。
路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
畅通路径的长度 是该路径途经的单元格总数。
*/


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        dist[0][0] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 && y == n - 1) {
                return dist[x][y];
            }
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n) { // 越界
                        continue;
                    }
                    if (grid[x + dx][y + dy] == 1 || dist[x + dx][y + dy] <= dist[x][y] + 1) { // 单元格值不为 0 或已被访问
                        continue;
                    }
                    dist[x + dx][y + dy] = dist[x][y] + 1;
                    q.push({ x + dx, y + dy });
                }
            }
        }
        return -1;
    }
};
