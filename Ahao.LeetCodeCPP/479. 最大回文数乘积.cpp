#include <cmath>
using namespace std;


/*
479. 最大回文数乘积
*/

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1;
        for (int left = upper;; --left) { // 枚举回文数的左半部分
            long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10; // 翻转左半部分到其自身末尾，构造回文数 p
            }
            for (long x = upper; x * x >= p; --x) {
                if (p % x == 0) { // x 是 p 的因子
                    return p % 1337;
                }
            }
        }
    }
};




class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        for (int half = pow(10, n) - 1; ; half--) { // 1、枚举回文数左半部分half
            // 2、构造回文数p
            long p = half;
            for (int i = half; i > 0; i /= 10) {
                p = p * 10 + i % 10;
            }
            // 3、判断该回位数能否被整除
            for (long i = pow(10, n) - 1; i * i >= p; i--) {
                if (p % i == 0) {
                    return p % 1337;
                }
            }
        }
    }
};