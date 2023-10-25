#include<vector>

using namespace std;

/*
2520. 统计能整除数字的位数

给你一个整数 num ，返回 num 中能整除 num 的数位的数目。

如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。
*/



class Solution {
public:
    int countDigits(int num) {
        int t = num, res = 0;
        while (t) {
            if (num % (t % 10) == 0) {
                res += 1;
            }
            t /= 10;
        }
        return res;
    }
};
