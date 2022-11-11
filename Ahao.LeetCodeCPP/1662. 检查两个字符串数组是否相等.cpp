#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    string join(vector<string>& words) {
        string ret = "";
        for (auto& s : words) {
            ret += s;
        }
        return ret;
    }

    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return join(word1) == join(word2);
    }
};


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int p1 = 0, p2 = 0, i = 0, j = 0;
        while (p1 < word1.size() && p2 < word2.size()) {
            if (word1[p1][i] != word2[p2][j]) {
                return false;
            }
            i++;
            if (i == word1[p1].size()) {
                p1++;
                i = 0;
            }
            j++;
            if (j == word2[p2].size()) {
                p2++;
                j = 0;
            }
        }
        return p1 == word1.size() && p2 == word2.size();
    }
};



/*
1662. 检查两个字符串数组是否相等
给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。

数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        for (auto& w : word1) a += w;
        for (auto& w : word2) b += w;
        return a == b;
    }
};
