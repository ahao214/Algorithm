#include<vector>
#include <string>

using namespace std;


/*
1017. 负二进制转换

给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。

注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
*/


class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        vector<int> bits(32);
        for (int i = 0; i < 32 && n != 0; i++) {
            if (n & 1) {
                bits[i]++;
                if (i & 1) {
                    bits[i + 1]++;
                }
            }
            n >>= 1;
        }
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int val = carry + bits[i];
            bits[i] = val & 1;
            carry = (val - bits[i]) / (-2);
        }
        int pos = 31;
        string res;
        while (pos >= 0 && bits[pos] == 0) {
            pos--;
        }
        while (pos >= 0) {
            res.push_back(bits[pos] + '0');
            pos--;
        }
        return res;
    }
};



class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0 || n == 1) {
            return to_string(n);
        }
        string res;
        while (n != 0) {
            int remainder = n & 1;
            res.push_back('0' + remainder);
            n -= remainder;
            n /= -2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    string baseNeg2(int n) {
        int val = 0x55555555 ^ (0x55555555 - n);
        if (val == 0) {
            return "0";
        }
        string res;
        while (val) {
            res.push_back('0' + (val & 1));
            val >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
