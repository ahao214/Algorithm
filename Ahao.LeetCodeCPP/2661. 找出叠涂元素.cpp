#include<vector>
#include <unordered_map>

using namespace std;


/*
2661. 找出叠涂元素

给你一个下标从 0 开始的整数数组 arr 和一个 m x n 的整数 矩阵 mat 。arr 和 mat 都包含范围 [1，m * n] 内的 所有 整数。

从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat 单元格涂色。

请你找出 arr 中在 mat 的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 i 。
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mp[mat[i][j]] = { i, j };
            }
        }
        vector<int> rowCnt(n, 0);
        vector<int> colCnt(m, 0);
        for (int i = 0; i < arr.size(); ++i) {
            auto& v = mp[arr[i]];
            ++rowCnt[v.first];
            if (rowCnt[v.first] == m) {
                return i;
            }
            ++colCnt[v.second];
            if (colCnt[v.second] == n) {
                return i;
            }
        }
        return -1;
    }
};
