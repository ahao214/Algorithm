#include<vector>
#include <numeric>

using namespace std;


/*
878. 第 N 个神奇数字

一个正整数如果能被 a 或 b 整除，那么它是神奇的。

给定三个整数 n , a , b ，返回第 n 个神奇的数字。因为答案可能很大，所以返回答案 对 109 + 7 取模 后的值。
*/

//方法一：容斥原理 + 二分查找
class Solution {
public:
    const int MOD = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a, b);
        long long r = (long long)n * min(a, b);
        int c = lcm(a, b);
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = mid / a + mid / b - mid / c;
            if (cnt >= n) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return (r + 1) % MOD;
    }

    long long lcm(long long a, long long b)
    {
        return a * b / (long long)gcd(a, b);
    };

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    };
};


//方法二：找规律
class Solution {
public:
    const int MOD = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        int c = lcm(a, b);
        int m = c / a + c / b - 1;
        int r = n % m;
        int res = (long long)c * (n / m) % MOD;
        if (r == 0) {
            return res;
        }
        int addA = a, addB = b;
        for (int i = 0; i < r - 1; ++i) {
            if (addA < addB) {
                addA += a;
            }
            else {
                addB += b;
            }
        }
        return (res + min(addA, addB) % MOD) % MOD;
    }

    long long lcm(long long a, long long b)
    {
        return a * b / (long long)gcd(a, b);
    };

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    };
};
