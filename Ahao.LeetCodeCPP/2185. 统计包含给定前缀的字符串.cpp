#include<vector>
#include <string>

using namespace std;

/*
2185. 统计包含给定前缀的字符串
简单
24
相关企业
给你一个字符串数组 words 和一个字符串 pref 。

返回 words 中以 pref 作为 前缀 的字符串的数目。

字符串 s 的 前缀 就是  s 的任一前导连续字符串。
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (string& word : words) {
            if (word.compare(0, pref.size(), pref) == 0) {
                res++;
            }
        }
        return res;
    }
};
