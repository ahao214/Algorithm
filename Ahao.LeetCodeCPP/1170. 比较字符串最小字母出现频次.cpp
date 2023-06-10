#include<vector>
#include <string>

using namespace std;


/*
1170. 比较字符串最小字母出现频次

定义一个函数 f(s)，统计 s  中（按字典序比较）最小字母的出现频次 ，其中 s 是一个非空字符串。

例如，若 s = "dcce"，那么 f(s) = 2，因为字典序最小字母是 "c"，它出现了 2 次。

现在，给你两个字符串数组待查表 queries 和词汇表 words 。对于每次查询 queries[i] ，需统计 words 中满足 f(queries[i]) < f(W) 的 词的数目 ，W 表示词汇表 words 中的每个词。

请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是第 i 次查询的结果。
*/


class Solution {
public:
    int f(string& s) {
        int cnt = 0;
        char ch = 'z';
        for (auto c : s) {
            if (c < ch) {
                ch = c;
                cnt = 1;
            }
            else if (c == ch) {
                cnt++;
            }
        }
        return cnt;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> count(12);
        for (auto& s : words) {
            count[f(s)]++;
        }
        for (int i = 9; i >= 1; i--) {
            count[i] += count[i + 1];
        }
        vector<int> res;
        for (auto& s : queries) {
            res.push_back(count[f(s) + 1]);
        }
        return res;
    }
};
