#include<vector>
#include <string>
#include<queue>

using namespace std;

/*
792. 匹配子序列的单词数

给定字符串 s 和字符串数组 words, 返回  words[i] 中是s的子序列的单词个数 。

字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。

例如， “ace” 是 “abcde” 的子序列。
*/


//二分查找
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (auto& w : words) {
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            int p = -1;
            for (char c : w) {
                auto& ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {
                    --res;
                    break;
                }
                p = *it;
            }
        }
        return res;
    }
};



//多指针
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<pair<int, int>>> queues(26);
        for (int i = 0; i < words.size(); ++i) {
            queues[words[i][0] - 'a'].emplace(i, 0);
        }
        int res = 0;
        for (char c : s) {
            auto& q = queues[c - 'a'];
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                ++j;
                if (j == words[i].size()) {
                    ++res;
                }
                else {
                    queues[words[i][j] - 'a'].emplace(i, j);
                }
            }
        }
        return res;
    }
};
