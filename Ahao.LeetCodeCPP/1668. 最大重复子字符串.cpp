#include<vector>
#include <algorithm>
#include<string>

using namespace std;


/*
1668. 最大重复子字符串
给你一个字符串 sequence ，如果字符串 word 连续重复 k 次形成的字符串是 sequence 的一个子字符串，那么单词 word 的 重复值为 k 。单词 word 的 最大重复值 是单词 word 在 sequence 中最大的重复值。如果 word 不是 sequence 的子串，那么重复值 k 为 0 。

给你一个字符串 sequence 和 word ，请你返回 最大重复值 k 。
*/

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        if (n < m) {
            return 0;
        }

        vector<int> f(n);
        for (int i = m - 1; i < n; ++i) {
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                if (sequence[i - m + j + 1] != word[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                f[i] = (i == m - 1 ? 0 : f[i - m]) + 1;
            }
        }

        return *max_element(f.begin(), f.end());
    }
};





class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        string s = word;
        while (s.size() <= sequence.size())
        {
            if (sequence.find(s) == -1)break;
            res++;
            s += word;
        }
        return res;
    }
};
