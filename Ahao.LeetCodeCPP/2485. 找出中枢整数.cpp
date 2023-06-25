#include<vector>

using namespace std;


/*
2485. 找出中枢整数

给你一个正整数 n ，找出满足下述条件的 中枢整数 x ：

1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和。
返回中枢整数 x 。如果不存在中枢整数，则返回 -1 。题目保证对于给定的输入，至多存在一个中枢整数。
*/

class Solution {
public:
    int pivotInteger(int n) {
        int t = (n * n + n) / 2;
        int x = sqrt(t);
        if (x * x == t) {
            return x;
        }
        return -1;
    }
};

