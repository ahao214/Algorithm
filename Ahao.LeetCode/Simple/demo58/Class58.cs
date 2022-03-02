using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo58
{
    /*
     58. 最后一个单词的长度
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
     */
    public class Class58
    {
        public int LengthOfLastWord(string s)
        {
            var i = s.Length - 1;
            while (i >= 0 && s[i] == ' ')
                i--;
            var start = i;
            while (start >= 0 && s[start] != ' ')
                start--;
            return i - start;
        }
    }
}
