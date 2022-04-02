using namespace std;

#pragma region 21. 斐波那契数列

/*
输入一个整数 n ，求斐波那契数列的第 n 项。

假定从 0 开始，第 0 项为 0。
*/

#pragma endregion

class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int one = 0, two = 1, res = 0;
        for (int i = 2; i <= n; i++)
        {
            res = one + two;
            one = two;
            two = res;
        }
        return res;
    }
};