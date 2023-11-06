#include<vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
318. 最大单词长度乘积

给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> map;
        int length = words.size();
        for (int i = 0; i < length; i++) {
            int mask = 0;
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                mask |= 1 << (word[j] - 'a');
            }
            if (map.count(mask)) {
                if (wordLength > map[mask]) {
                    map[mask] = wordLength;
                }
            }
            else {
                map[mask] = wordLength;
            }

        }
        int maxProd = 0;
        for (auto [mask1, _] : map) {
            int wordLength1 = map[mask1];
            for (auto [mask2, _] : map) {
                if ((mask1 & mask2) == 0) {
                    int wordLength2 = map[mask2];
                    maxProd = max(maxProd, wordLength1 * wordLength2);
                }
            }
        }
        return maxProd;
    }
};


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> masks(length);
        for (int i = 0; i < length; i++) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};
