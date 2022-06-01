using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo473
{
    public class Class473
    {
        /// <summary>
        /// 回溯
        /// </summary>
        /// <param name="matchsticks"></param>
        /// <returns></returns>
        public bool Makesquare(int[] matchsticks)
        {
            int totalLen = matchsticks.Sum();
            if (totalLen % 4 != 0)
            {
                return false;
            }
            Array.Sort(matchsticks);
            for (int i = 0, j = matchsticks.Length - 1; i < j; i++, j--)
            {
                int temp = matchsticks[i];
                matchsticks[i] = matchsticks[j];
                matchsticks[j] = temp;
            }

            int[] edges = new int[4];
            return DFS(0, matchsticks, edges, totalLen / 4);
        }

        public bool DFS(int index, int[] matchsticks, int[] edges, int len)
        {
            if (index == matchsticks.Length)
            {
                return true;
            }
            for (int i = 0; i < edges.Length; i++)
            {
                edges[i] += matchsticks[index];
                if (edges[i] <= len && DFS(index + 1, matchsticks, edges, len))
                {
                    return true;
                }
                edges[i] -= matchsticks[index];
            }
            return false;
        }


        /// <summary>
        /// 方法二：状态压缩 + 动态规划
        /// </summary>
        /// <param name="matchsticks"></param>
        /// <returns></returns>
        public bool Makesquare2(int[] matchsticks)
        {
            int totalLen = matchsticks.Sum();
            if (totalLen % 4 != 0)
            {
                return false;
            }
            int len = totalLen / 4, n = matchsticks.Length;
            int[] dp = new int[1 << n];
            Array.Fill(dp, -1);
            dp[0] = 0;
            for (int s = 1; s < (1 << n); s++)
            {
                for (int k = 0; k < n; k++)
                {
                    if ((s & (1 << k)) == 0)
                    {
                        continue;
                    }
                    int s1 = s & ~(1 << k);
                    if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len)
                    {
                        dp[s] = (dp[s1] + matchsticks[k]) % len;
                        break;
                    }
                }
            }
            return dp[(1 << n) - 1] == 0;
        }


    }
}
