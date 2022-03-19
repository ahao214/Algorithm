using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2047
{
    /*
     2047. 句子中的有效单词数
    句子仅由小写字母（'a' 到 'z'）、数字（'0' 到 '9'）、连字符（'-'）、标点符号（'!'、'.' 和 ','）以及空格（' '）组成。每个句子可以根据空格分解成 一个或者多个 token ，这些 token 之间由一个或者多个空格 ' ' 分隔。

    如果一个 token 同时满足下述条件，则认为这个 token 是一个有效单词：

    仅由小写字母、连字符和/或标点（不含数字）。
    至多一个 连字符 '-' 。如果存在，连字符两侧应当都存在小写字母（"a-b" 是一个有效单词，但 "-ab" 和 "ab-" 不是有效单词）。
    至多一个 标点符号。如果存在，标点符号应当位于 token 的 末尾 。
    这里给出几个有效单词的例子："a-b."、"afad"、"ba-c"、"a!" 和 "!" 。

    给你一个字符串 sentence ，请你找出并返回 sentence 中 有效单词的数目 。
     */
    public class Class2047
    {
        public int CountValidWords(string sentence)
        {
            int n = sentence.Length;
            int l = 0, r = 0;
            int ret = 0;
            while (true)
            {
                while (l < n && sentence[l] == ' ')
                {
                    l++;
                }
                if (l >= n)
                {
                    break;
                }
                r = l + 1;
                while (r < n && sentence[r] != ' ')
                {
                    r++;
                }
                if (isValid(sentence.Substring(l, r - l)))
                { // 判断根据空格分解出来的 token 是否有效
                    ret++;
                }
                l = r + 1;
            }
            return ret;
        }

        public bool isValid(string word)
        {
            int n = word.Length;
            bool hasHyphens = false;
            for (int i = 0; i < n; i++)
            {
                if (char.IsDigit(word[i]))
                {
                    return false;
                }
                else if (word[i] == '-')
                {
                    if (hasHyphens == true || i == 0 || i == n - 1 || !char.IsLetter(word[i - 1]) || !char.IsLetter(word[i + 1]))
                    {
                        return false;
                    }
                    hasHyphens = true;
                }
                else if (word[i] == '!' || word[i] == '.' || word[i] == ',')
                {
                    if (i != n - 1)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}
