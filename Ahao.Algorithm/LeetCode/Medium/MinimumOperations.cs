using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// LCP 19. 秋叶收藏集
    /// </summary>
    public class MinimumOperations
    {
        public int Method(string leaves)
        {
            int n = leaves.Length;
            int[,] dp = new int[3, n];
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    dp[i, j] = 100000000;
                }
            }
            dp[0, 0] = leaves[0] == 'r' ? 0 : 1;
            for (int i = 1; i < n; i++)
            {
                dp[0, i] = dp[0, i - 1] + (leaves[i] == 'y' ? 1 : 0);
                dp[1, i] = Math.Min(dp[0, i - 1], dp[1, i - 1]) + (leaves[i] == 'r' ? 1 : 0);
                dp[2, i] = Math.Min(dp[1, i - 1], dp[2, i - 1]) + (leaves[i] == 'y' ? 1 : 0);
            }
            return dp[2, n - 1];
        }
    }
}
