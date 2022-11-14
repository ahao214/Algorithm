#include<vector>
#include <algorithm>

using namespace std;


/*
2165. 重排数字的最小值
给你一个整数 num 。重排 num 中的各位数字，使其值 最小化 且不含 任何 前导零。

返回不含前导零且值最小的重排数字。

注意，重排各位数字后，num 的符号不会改变。
*/
class Solution {
public:
    long long smallestNumber(long long num)
    {
        vector<int>a(10);
        if (num < 0)
        {
            num = -num;
            while (num)
            {
                a[num % 10]++;
                num /= 10;
            }
            long long res = 0;
            for (int i = 9; i >= 0; --i)
                while (a[i]--)
                    res = res * 10ll + i;
            return -res;
        }
        if (num == 0)return 0;
        while (num)
        {
            a[num % 10]++;
            num /= 10;
        }
        long long res = 0;
        for (int i = 1; i <= 9; ++i)
            if (a[i])
            {
                a[i]--;
                res = res * 10ll + i;
                break;
            }
        while (a[0]--)
            res = res * 10;
        for (int i = 1; i <= 9; i++)
            while (a[i]--)
                res = res * 10ll + i;
        return res;
    }
};

using LL = long long;
class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;
        }
        vector<int> data;
        bool fu = false;
        if (num < 0) {
            fu = true;
            num = -num;
        }
        while(num > 0) {
            data.push_back(num % 10);
            num /= 10;
        }
        LL ans = 0;
        sort(data.begin(), data.end());
        if (fu) {
            //负数
            for (int i = data.size() - 1; i >= 0; i--) {
                ans *= 10;
                ans += data[i];
            }
            return -ans;
        }
        for (int i = 0; i < data.size(); i++) {
            if (data[i] != 0) {
                swap(data[i], data[0]);
                break;
            }
        }
        for (int i = 0; i < data.size(); i++) {
            ans *= 10;
            ans += data[i];
        }
        return ans;
    }
};