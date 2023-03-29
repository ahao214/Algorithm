using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1641
{
    public class Class1641
    {
        public int CountVowelStrings(int n)
        {
            int[] dp = new int[5];
            Array.Fill(dp, 1);
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < 5; j++)
                {
                    dp[j] += dp[j - 1];
                }
            }
            return dp.Sum();
        }

        /// <summary>
        /// 组合数字
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int CountVowelStrings2(int n)
        {
            return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
        }


    }
}
