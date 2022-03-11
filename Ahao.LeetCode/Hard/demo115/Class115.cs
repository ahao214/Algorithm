using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo115
{
    /*
     115. 不同的子序列
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。
     */
    public class Class115
    {
        public int NumDistinct(string s, string t)
        {
            int ilen = s.Length;
            int jlen = t.Length;
            int[,] dp = new int[ilen + 1, jlen + 1];
            dp[0, 0] = 1;
            for (int i = 1; i <= ilen; i++)
                for (int j = 1; j <= jlen; j++)
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        for (int k = 0; k < i; k++)
                            dp[i, j] += dp[k, j - 1];
                    }
                }
            var ans = 0;
            for (int i = 0; i <= ilen; i++)
                ans += dp[i, jlen];
            return ans;
        }
    }
}
