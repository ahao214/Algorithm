#include<vector>
#include <string>

using namespace std;

/*
1945. 字符串转化后的各位数字之和
给你一个由小写字母组成的字符串 s ，以及一个整数 k 。

首先，用字母在字母表中的位置替换该字母，将 s 转化 为一个整数（也就是，'a' 用 1 替换，'b' 用 2 替换，... 'z' 用 26 替换）。接着，将整数 转换 为其 各位数字之和 。共重复 转换 操作 k 次 。

例如，如果 s = "zbax" 且 k = 2 ，那么执行下述步骤后得到的结果是整数 8 ：

转化："zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
转换 #1：262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
转换 #2：17 ➝ 1 + 7 ➝ 8
返回执行上述操作后得到的结果整数。
*/

class Solution {
public:
    int getLucky(string s, int k) {
        string digits;
        for (char ch : s) {
            digits += to_string(ch - 'a' + 1);
        }

        for (int i = 1; i <= k && digits.size() > 1; ++i) {
            int sum = 0;
            for (char ch : digits) {
                sum += ch - '0';
            }
            digits = to_string(sum);
        }

        return stoi(digits);
    }
};
