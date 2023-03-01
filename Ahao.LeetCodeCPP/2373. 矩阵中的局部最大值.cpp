#include<vector>

using namespace std;

/*
2373. 矩阵中的局部最大值

给你一个大小为 n x n 的整数矩阵 grid 。

生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：

maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。

返回生成的矩阵。
*/


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        res[i][j] = max(res[i][j], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};
