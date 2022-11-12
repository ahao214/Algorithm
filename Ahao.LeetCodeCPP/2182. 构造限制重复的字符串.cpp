#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
2182. 构造限制重复的字符串
给你一个字符串 s 和一个整数 repeatLimit ，用 s 中的字符构造一个新字符串 repeatLimitedString ，使任何字母 连续 出现的次数都不超过 repeatLimit 次。你不必使用 s 中的全部字符。

返回 字典序最大的 repeatLimitedString 。

如果在字符串 a 和 b 不同的第一个位置，字符串 a 中的字母在字母表中出现时间比字符串 b 对应的字母晚，则认为字符串 a 比字符串 b 字典序更大 。如果字符串中前 min(a.length, b.length) 个字符都相同，那么较长的字符串字典序更大。
*/
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int>m;
        for (auto item : s)
        {
            m[item]++;
        }
        string ans = "";
        char last = '1';
        int len = 0;
        bool flag = true;
        while (flag)
        {
            for (int now = 'z'; now >= 'a'; now--)
            {
                if (m[now] && (now != last || (len < repeatLimit)))
                {
                    ans += now;
                    m[now]--;
                    if (now == last)
                        len++;
                    else
                    {
                        len = 1;
                        last = now;
                    }
                    break;
                }
                if (now == 'a')
                    flag = false;
            }
        }
        return ans;
    }
};