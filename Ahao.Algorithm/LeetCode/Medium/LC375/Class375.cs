using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 375. 猜数字大小 II
    /// </summary>
    public class Class375
    {
        public int GetMoneyAmount(int n)
        {
            int[,] f = new int[n + 1, n + 1];
            for (int i = n - 1; i >= 1; i--)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    int minCost = int.MaxValue;
                    for (int k = i; k < j; k++)
                    {
                        int cost = k + Math.Max(f[i, k - 1], f[k + 1, j]);
                        minCost = Math.Min(minCost, cost);
                    }
                    f[i, j] = minCost;
                }
            }
            return f[1, n];
        }
    }
}
