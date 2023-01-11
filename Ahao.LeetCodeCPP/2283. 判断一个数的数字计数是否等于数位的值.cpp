#include<vector>
#include <unordered_map>

using namespace std;

/*
2283. 判断一个数的数字计数是否等于数位的值

给你一个下标从 0 开始长度为 n 的字符串 num ，它只包含数字。

如果对于 每个 0 <= i < n 的下标 i ，都满足数位 i 在 num 中出现了 num[i]次，那么请你返回 true ，否则返回 false 。
*/

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> h;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            h[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++) {
            int v = num[i] - '0';
            if (h[i] != v) {
                return false;
            }
        }
        return true;
    }
};

