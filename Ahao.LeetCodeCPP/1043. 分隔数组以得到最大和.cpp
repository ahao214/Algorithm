#include<vector>

using namespace std;

/*
1043. 分隔数组以得到最大和

给你一个整数数组 arr，请你将该数组分隔为长度 最多 为 k 的一些（连续）子数组。分隔完成后，每个子数组的中的所有值都会变为该子数组中的最大值。

返回将数组分隔变换后能够得到的元素最大和。本题所用到的测试用例会确保答案是一个 32 位整数。
*/

class Solution {
public:
    using ll = long long;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) {
            int maxValue = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                d[i] = max(d[i], d[j] + maxValue * (i - j));
                if (j > 0) {
                    maxValue = max(maxValue, arr[j - 1]);
                }
            }
        }
        return d[n];
    }
};
