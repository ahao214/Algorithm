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

