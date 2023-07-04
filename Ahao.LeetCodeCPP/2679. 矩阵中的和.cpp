#include<vector>
#include<algorithm>

using namespace std;

/*
2679. 矩阵中的和

给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0 。你需要执行以下操作直到矩阵变为空：

矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。
在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。
请你返回最后的 分数 。
*/



class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        int n = nums[0].size();
        for (int i = 0; i < m; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, nums[i][j]);
            }
            res += maxVal;
        }
        return res;
    }
};



class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        int n = nums[0].size();
        vector<priority_queue<int>> pq(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq[i].emplace(nums[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, pq[i].top());
                pq[i].pop();
            }
            res += maxVal;
        }
        return res;
    }
};
