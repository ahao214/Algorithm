using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1039
{

    public class Class1039
    {
        public int MinScoreTriangulation(int[] values)
        {
            int n = values.Length;
            int[][] f = new int[n][];
            for (int i = 0; i < n; i++)
            {
                f[i] = new int[n];
            }

            for (int i = n - 3; i >= 0; i--)
            {
                for (int j = i + 2; j < n; j++)
                {
                    f[i][j] = int.MaxValue;
                    for (int k = i + 1; k < j; k++)
                    {
                        f[i][j] = Math.Min(f[i][j], f[i][k] + f[k][j] + values[i] * values[j] * values[k]);
                    }
                }
            }
            return f[0][n - 1];
        }
    }
}
