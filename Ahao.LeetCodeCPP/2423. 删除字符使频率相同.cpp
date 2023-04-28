#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
2423. 删除字符使频率相同

给你一个下标从 0 开始的字符串 word ，字符串只包含小写英文字母。你需要选择 一个 下标并 删除 下标处的字符，使得 word 中剩余每个字母出现 频率 相同。

如果删除一个字母后，word 中剩余所有字母的出现频率都相同，那么返回 true ，否则返回 false 。

注意：

字母 x 的 频率 是这个字母在字符串中出现的次数。
你 必须 恰好删除一个字母，不能一个字母都不删除。
*/


class Solution {
public:
    bool equalFrequency(string word) {
        int charCount[26] = { 0 };
        for (char& c : word) {
            charCount[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 0) {
                continue;
            }
            charCount[i]--;
            unordered_set<int> frequency;
            for (int f : charCount) {
                if (f > 0) {
                    frequency.insert(f);
                }
            }
            if (frequency.size() == 1) {
                return true;
            }
            charCount[i]++;
        }
        return false;
    }
};



class Solution {
public:
    bool equalFrequency(string word) {
        int charCount[26] = { 0 };
        for (char c : word) {
            charCount[c - 'a']++;
        }
        unordered_map<int, int> freqCount;
        for (int c : charCount) {
            if (c > 0) {
                freqCount[c]++;
            }
        }
        for (int c : charCount) {
            if (c == 0) {
                continue;
            }
            freqCount[c]--;
            if (freqCount[c] == 0) {
                freqCount.erase(c);
            }
            if (c - 1 > 0) {
                freqCount[c - 1]++;
            }
            if (freqCount.size() == 1) {
                return true;
            }
            if (c - 1 > 0) {
                freqCount[c - 1]--;
                if (freqCount[c - 1] == 0) {
                    freqCount.erase(c - 1);
                }
            }
            freqCount[c]++;
        }
        return false;
    }
};
