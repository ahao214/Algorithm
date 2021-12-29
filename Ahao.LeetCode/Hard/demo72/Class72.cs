using System;

namespace Ahao.LeetCode.Hard.demo72
{
    /// <summary>
    /// 72.编辑距离
    /// </summary>
    public class Class72
    {
        public int MinDistance(string word1, string word2)
        {
            //【dp数组定义】w1转为w2所需的最小操作数
            int[,] dp = new int[word1.Length + 1, word2.Length + 1];
            //【初始化】
            for (int i = 0; i <= word1.Length; i++)
            {
                dp[i, 0] = i;
            }
            for (int j = 0; j <= word2.Length; j++)
            {
                dp[0, j] = j;
            }

            //【状态转移】
            for (int i = 1; i <= word1.Length; i++)
            {
                for (int j = 1; j <= word2.Length; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                        //如果最后一位相等，最少操作数无影响
                        dp[i, j] = dp[i - 1, j - 1];
                    else
                        //如果不相等，到d[i,j]一共有3种状态，取最小：替换、w1新增w2的最后1位、w2新增w1的最后1位
                        dp[i, j] = Math.Min(dp[i - 1, j - 1], Math.Min(dp[i - 1, j], dp[i, j - 1])) + 1;
                }
            }
            return dp[word1.Length, word2.Length];
        }
    }
}

