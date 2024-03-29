#include<vector>

using namespace std;



/*
201. 数字范围按位与
给你两个整数 left 和 right ，表示区间 [left, right]
返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0)
            return 0;
        while (left < right)
        {
            right &= (right - 1);
        }
        return right;
    }
};