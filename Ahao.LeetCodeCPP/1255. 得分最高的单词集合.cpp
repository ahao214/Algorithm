#include<vector>
#include <string>

using namespace std;

/*
1255. 得分最高的单词集合

你将会得到一份单词表 words，一个字母表 letters （可能会有重复字母），以及每个字母对应的得分情况表 score。

请你帮忙计算玩家在单词拼写游戏中所能获得的「最高得分」：能够由 letters 里的字母拼写出的 任意 属于 words 单词子集中，分数最高的单词集合的得分。

单词拼写游戏的规则概述如下：

玩家需要用字母表 letters 里的字母来拼写单词表 words 中的单词。
可以只使用字母表 letters 中的部分字母，但是每个字母最多被使用一次。
单词表 words 中每个单词只能计分（使用）一次。
根据字母得分情况表score，字母 'a', 'b', 'c', ... , 'z' 对应的得分分别为 score[0], score[1], ..., score[25]。
本场游戏的「得分」是指：玩家所拼写出的单词集合里包含的所有字母的得分之和。
*/

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), res = 0;
        vector<int> count(26);
        for (auto c : letters) {
            count[c - 'a']++;
        }
        for (int s = 1; s < (1 << n); s++) {
            vector<int> wordCount(26); // 统计子集 s 所有单词的字母数目
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) { // words[k] 不在子集 s 中
                    continue;
                }
                for (auto c : words[k]) {
                    wordCount[c - 'a']++;
                }
            }
            bool ok = true; // 判断子集 s 是否合法
            int sum = 0; // 保存子集 s 的得分
            for (int i = 0; i < 26; i++) {
                sum += score[i] * wordCount[i];
                ok = ok && (wordCount[i] <= count[i]);
            }
            if (ok) {
                res = max(res, sum);
            }
        }
        return res;
    }
};
