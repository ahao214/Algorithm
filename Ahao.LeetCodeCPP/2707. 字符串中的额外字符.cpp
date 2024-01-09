#include<vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
2707. 字符串中的额外字符

给你一个下标从 0 开始的字符串 s 和一个单词字典 dictionary 。你需要将 s 分割成若干个 互不重叠 的子字符串，每个子字符串都在 dictionary 中出现过。s 中可能会有一些 额外的字符 不在任何子字符串中。

请你采取最优策略分割 s ，使剩下的字符 最少 。
*/


class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> d(n + 1, INT_MAX);
        unordered_map<string, int> mp;
        for (auto s : dictionary) {
            mp[s]++;
        }
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1] + 1;
            for (int j = i - 1; j >= 0; j--) {
                if (mp.count(s.substr(j, i - j))) {
                    d[i] = min(d[i], d[j]);
                }
            }
        }
        return d[n];
    }
};



class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool track(Trie*& node, char ch) {
        if (node == nullptr || node->children[ch - 'a'] == nullptr) {
            node = nullptr;
            return false;
        }
        node = node->children[ch - 'a'];
        return node->isEnd;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> d(n + 1, INT_MAX);
        Trie trie;
        for (auto s : dictionary) {
            reverse(s.begin(), s.end());
            trie.insert(s);
        }
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1] + 1;
            Trie* node = &trie;
            for (int j = i - 1; j >= 0; j--) {
                if (trie.track(node, s[j])) {
                    d[i] = min(d[i], d[j]);
                }
            }
        }
        return d[n];
    }
};
