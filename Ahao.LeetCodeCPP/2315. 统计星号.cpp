#include<vector>
#include <string>

using namespace std;

/*
2315. 统计星号

给你一个字符串 s ，每 两个 连续竖线 '|' 为 一对 。换言之，第一个和第二个 '|' 为一对，第三个和第四个 '|' 为一对，以此类推。

请你返回 不在 竖线对之间，s 中 '*' 的数目。

注意，每个竖线 '|' 都会 恰好 属于一个对。
*/


class Solution {
public:
    int countAsterisks(string s) {
        bool valid = true;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '|') {
                valid = !valid;
            }
            else if (c == '*' && valid) {
                res++;
            }
        }
        return res;
    }
};
