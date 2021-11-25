using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo458
{
    /// <summary>
    /// 458. 可怜的小猪
    /// </summary>
    public class Class458
    {
        /// <summary>
        /// 动态规划
        /// </summary>
        /// <param name="buckets"></param>
        /// <param name="minutesToDie"></param>
        /// <param name="minutesToTest"></param>
        /// <returns></returns>
        public int PoorPigs(int buckets, int minutesToDie, int minutesToTest)
        {
            if (buckets == 1)
            {
                return 0;
            }


            int[,] combinations = new int[buckets + 1, buckets + 1];
            combinations[0, 0] = 1;
            int iterations = minutesToTest / minutesToDie;
            int[,] f = new int[buckets, iterations + 1];
            for (int i = 0; i < buckets; i++)
            {
                f[i, 0] = 1;
            }
            for (int j = 0; j <= iterations; j++)
            {
                f[0, j] = 1;
            }

            for (int i = 1; i < buckets; i++)
            {
                combinations[i, 0] = 1;
                combinations[i, i] = 1;

                for (int j = 1; j < i; j++)
                {
                    combinations[i, j] = combinations[i - 1, j - 1] + combinations[i - 1, j];
                }

                for (int j = 1; j <= iterations; j++)
                {
                    for (int k = 0; k <= i; k++)
                    {
                        f[i, j] += f[k, j - 1] * combinations[i, i - k];
                    }
                }
                if (f[i, iterations] >= buckets)
                {
                    return i;
                }
            }
            return 0;
        }
    }
}
