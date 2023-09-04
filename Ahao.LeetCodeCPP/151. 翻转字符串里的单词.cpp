#include<vector>
#include <string>

using namespace std;



/*
151. 翻转字符串里的单词

给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

说明：

输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
翻转后单词间应当仅用一个空格分隔。
翻转后的字符串中不应包含额外的空格。
*/
class Solution {
public:
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};



class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')continue;
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ')
                s[t++] = s[j++];
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            k = t, i = j;
        }
        if (k)k--;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};