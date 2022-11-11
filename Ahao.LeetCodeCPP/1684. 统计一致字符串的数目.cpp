#include<vector>
#include<string>

using namespace std;

/*
1684. 统计一致字符串的数目

简单

给你一个由不同字符组成的字符串 allowed 和一个字符串数组 words 。如果一个字符串的每一个字符都在 allowed 中，就称这个字符串是 一致字符串 。

请你返回 words 数组中 一致字符串 的数目。
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (auto c : allowed) {
            mask |= 1 << (c - 'a');
        }
        int res = 0;
        for (auto&& word : words) {
            int mask1 = 0;
            for (auto c : word) {
                mask1 |= 1 << (c - 'a');
            }
            if ((mask1 | mask) == mask) {
                res++;
            }
        }
        return res;
    }
};


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        for (auto& word : words)
        {
            bool flag = true;
            for (auto c : word)
            {
                if (allowed.find(c) == -1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) res++;
        }
        return res;
    }
};