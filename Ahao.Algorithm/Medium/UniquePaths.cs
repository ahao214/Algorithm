using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 62.不同路径
    /// </summary>
    public class UniquePaths
    {
        public int Method(int m, int n)
        {            
            int[,] dp = new int[1, m + 1];
            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < m + 1; j++)
                {
                    if (j == 1 || i == 1)
                    {
                        dp[0, j] = 1;
                    }
                    else
                    {
                        dp[0, j] = dp[0, j] + dp[0, j - 1];
                    }
                }
            }
            return dp[0, m];
        }
    }
}
