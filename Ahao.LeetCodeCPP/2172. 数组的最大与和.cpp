#include<vector>

using namespace std;


/*
2172. 数组的最大与和
给你一个长度为 n 的整数数组 nums 和一个整数 numSlots ，满足2 * numSlots >= n 。总共有 numSlots 个篮子，编号为 1 到 numSlots 。

你需要把所有 n 个整数分到这些篮子中，且每个篮子 至多 有 2 个整数。一种分配方案的 与和 定义为每个数与它所在篮子编号的 按位与运算 结果之和。

比方说，将数字 [1, 3] 放入篮子 1 中，[4, 6] 放入篮子 2 中，这个方案的与和为 (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4 。
请你返回将 nums 中所有数放入 numSlots 个篮子中的最大与和。
*/
class Solution {

    int f[20001], b[10];

public:
    int maximumANDSum(vector<int>& a, int m) {
        int n = a.size();
        memset(f, 0, sizeof(f));
        int l = 1;
        for (int i = 1; i <= m; i++)
            l *= 3;

        for (int i = 0; i < n; i++) {
            for (int j = l - 1; j >= 0; --j) {
                for (int k = 1, l = j; k <= m; k++, l /= 3)
                    b[k] = l % 3;
                int x = 1;
                for (int k = 1; k <= m; k++, x *= 3)
                    if (b[k] != 2) {
                        f[j + x] = max(f[j + x], f[j] + (a[i] & k));
                    }
            }
        }
        return f[l - 1];
    }
};
