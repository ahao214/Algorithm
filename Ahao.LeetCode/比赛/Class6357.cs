using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6357. 最少得分子序列  

给你两个字符串 s 和 t 。

你可以从字符串 t 中删除任意数目的字符。

如果没有从字符串 t 中删除字符，那么得分为 0 ，否则：

令 left 为删除字符中的最小下标。
令 right 为删除字符中的最大下标。
字符串的得分为 right - left + 1 。

请你返回使 t 成为 s 子序列的最小得分。

一个字符串的 子序列 是从原字符串中删除一些字符后（也可以一个也不删除），剩余字符不改变顺序得到的字符串。（比方说 "ace" 是 "abcde" 的子序列，但是 "aec" 不是）。

 

示例 1：

输入：s = "abacaba", t = "bzaa"
输出：1
解释：这个例子中，我们删除下标 1 处的字符 "z" （下标从 0 开始）。
字符串 t 变为 "baa" ，它是字符串 "abacaba" 的子序列，得分为 1 - 1 + 1 = 1 。
1 是能得到的最小得分。
     */
    public class Class6357
    {
        public int MinimumScore(string s, string t)
        {
            int[] dp = new int[s.Length + 1];
            int min = t.Length;
            for (int i = 0, j = 0; i < s.Length; i++)
            {
                dp[i + 1] = j += j < t.Length && s[i] == t[j] ? 1 : 0;
            }
            for (int i = s.Length - 1, j = t.Length - 1; i >= 0; i--)
            {
                min = Math.Min(min, Math.Max(0, (j -= j >= 0 && s[i] == t[j] ? 1 : 0) - dp[i] + 1));
            }
            return Math.Min(min, t.Length - dp[s.Length]);
        }
    }
}
