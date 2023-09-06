#include<vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
2309. 兼具大小写的最好英文字母

给你一个由英文字母组成的字符串 s ，请你找出并返回 s 中的 最好 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。

最好 英文字母的大写和小写形式必须 都 在 s 中出现。

英文字母 b 比另一个英文字母 a 更好 的前提是：英文字母表中，b 在 a 之 后 出现。
*/


//哈希表
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> ht(s.begin(), s.end());
        for (int i = 25; i >= 0; i--) {
            if (ht.count('a' + i) > 0 && ht.count('A' + i) > 0) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};


//位运算
class Solution {
public:
    string greatestLetter(string s) {
        int lower = 0, upper = 0;
        for (auto c : s) {
            if (islower(c)) {
                lower |= 1 << (c - 'a');
            }
            else {
                upper |= 1 << (c - 'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (lower & upper & (1 << i)) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};



class Solution {
public:
    string greatestLetter(string s) {
        vector<int> letters(128, 0);
        for (auto c : s)
        {
            letters[c]++;
        }
        for (int i = 'Z'; i >= 'A'; i--)
        {
            if (letters[i] > 0 && letters[i - 'A' + 'a'] > 0)
                return string(1, i);
        }
        return "";
    }
};