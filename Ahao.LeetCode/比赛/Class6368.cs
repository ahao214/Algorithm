﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{
    /*
     6368. 找出字符串的可整除数组 

给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。

word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：

如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。
示例 1：

输入：word = "998244353", m = 3
输出：[1,1,0,0,0,1,1,0,0]
解释：仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。
示例 2：

输入：word = "1010", m = 10
输出：[0,1,0,1]
解释：仅有 2 个前缀可以被 10 整除："10" 和 "1010" 。
     */
    public class Class6368
    {
        public int[] DivisibilityArray(string word, int m)
        {
            int n = word.Length;
            int[] div = new int[n];
            long mod = 0;
            for (int i = 0; i < n; i++)
            {
                mod = mod * 10 + word[i] - '0';
                mod %= m;
                if (mod == 0)
                    div[i] = 1;
                else
                    div[i] = 0;
            }

            return div;
        }
    }
}
