using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo521
{
    /*
     521. 最长特殊序列 Ⅰ
给你两个字符串 a 和 b，请返回 这两个字符串中 最长的特殊序列  。如果不存在，则返回 -1 。

「最长特殊序列」 定义如下：该序列为 某字符串独有的最长子序列（即不能是其他字符串的子序列） 。

字符串 s 的子序列是在从 s 中删除任意数量的字符后可以获得的字符串。

例如，“abc” 是 “aebdc” 的子序列，因为您可以删除 “aebdc” 中的下划线字符来得到 “abc” 。 “aebdc” 的子序列还包括 “aebdc” 、 “aeb” 和 “” (空字符串)。
     */
    public class Class521
    {
        public int FindLUSlength(string a, string b)
        {
            if (a.Equals(b))
                return -1;
            else
                return Math.Max(a.Length, b.Length);
        }
    }
}
