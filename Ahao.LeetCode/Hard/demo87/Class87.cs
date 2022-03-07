using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo87
{
    /*
     87. 扰乱字符串
使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。
     */
    public class Class87
    {
        public bool IsScramble(string s1, string s2)
        {
            if (s1.Length != s2.Length)
            {
                return false;
            }
            int n = s1.Length;
            bool[,,] dp = new bool[n, n, n];//[s1子串起点下标，s2子串起点下标，字串长度（0表示长度1）]
                                            //初始化DP
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i, j, 0] = s1[i] == s2[j];
                }
            }
            for (int l = 1; l < n; l++)
            {
                for (int i = 0; i < n - l; i++)
                {
                    for (int j = 0; j < n - l; j++)
                    {
                        for (int w = 1; w < l + 1; w++)
                        {
                            dp[i, j, l] |= dp[i, j, w - 1] && dp[i + w, j + w, l - w];
                            dp[i, j, l] |= dp[i, j + l - w + 1, w - 1] && dp[i + w, j, l - w];
                            if (dp[i, j, l])                            
                                break;                            
                        }
                    }
                }
            }
            return dp[0, 0, n - 1];
        }

    }
}
