#include<vector>
#include <string>
#include<unordered_map>


using namespace std;

/*
1156. 单字符重复子串的最大长度

如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。

给你一个字符串 text，你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。
*/


class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> count;
        for (auto c : text) {
            count[c]++;
        }

        int res = 0;
        for (int i = 0; i < text.size(); ) {
            // step1: 找出当前连续的一段 [i, j)
            int j = i;
            while (j < text.size() && text[j] == text[i]) {
                j++;
            }
            int cur_cnt = j - i;

            // step2: 如果这一段长度小于该字符出现的总数，并且前面或后面有空位，则使用 cur_cnt + 1 更新答案
            if (cur_cnt < count[text[i]] && (j < text.size() || i > 0)) {
                res = max(res, cur_cnt + 1);
            }

            // step3: 找到这一段后面与之相隔一个不同字符的另一段 [j + 1, k)，如果不存在则 k = j + 1 
            int k = j + 1;
            while (k < text.size() && text[k] == text[i]) {
                k++;
            }
            res = max(res, min(k - i, count[text[i]]));
            i = j;
        }
        return res;
    }
};
