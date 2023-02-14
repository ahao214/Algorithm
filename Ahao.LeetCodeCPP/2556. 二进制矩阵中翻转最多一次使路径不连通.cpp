#include<vector>

using namespace std;



/*
2556. 二进制矩阵中翻转最多一次使路径不连通

给你一个下标从 0 开始的 m x n 二进制 矩阵 grid 。你可以从一个格子 (row, col) 移动到格子 (row + 1, col) 或者 (row, col + 1) ，前提是前往的格子值为 1 。如果从 (0, 0) 到 (m - 1, n - 1) 没有任何路径，我们称该矩阵是 不连通 的。

你可以翻转 最多一个 格子的值（也可以不翻转）。你 不能翻转 格子 (0, 0) 和 (m - 1, n - 1) 。

如果可以使矩阵不连通，请你返回 true ，否则返回 false 。

注意 ，翻转一个格子的值，可以使它的值从 0 变 1 ，或从 1 变 0 。
*/
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1) continue;
                if ((i + 1 >= m || grid[i + 1][j] == 0) && (j + 1 >= n || grid[i][j + 1] == 0))
                    grid[i][j] = 0;
            }
        if (grid[0][0] == 0) return true;

        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        for (int k = 0; k < m + n - 3; k++)
        {
            if (y1 + 1 < n && grid[x1][y1 + 1] == 1)
                y1++;
            else
                x1++;

            if (x2 + 1 < m && grid[x2 + 1][y2] == 1)
                x2++;
            else
                y2++;

            if (x1 == x2 && y1 == y2)
                return true;
        }

        return false;
    }
};