#include<vector>

using namespace std;



/*
2180. 统计各位数字之和为偶数的整数个数
给你一个正整数 num ，请你统计并返回 小于或等于 num 且各位数字之和为 偶数 的正整数的数目。

正整数的 各位数字之和 是其所有位上的对应数字相加的结果。
*/
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int tmp = 0;
            int x = i;
            while (x) {
                tmp += x % 10;
                x /= 10;
            }
            if (tmp % 2 == 0)
                ++ans;
        }
        return ans;
    }
};


class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 1; i <= num; i++) {
            int x = i, sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            if (sum % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};
