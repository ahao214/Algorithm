using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1223
{
    public class Class1223
    {

        const int MOD = 1000000007;

        public int DieSimulator(int n, int[] rollMax)
        {
            int[][][] d = new int[n + 1][][];
            for (int i = 0; i <= n; i++)
            {
                d[i] = new int[6][];
                for (int j = 0; j < 6; j++)
                {
                    d[i][j] = new int[16];
                }
            }
            for (int j = 0; j < 6; j++)
            {
                d[1][j][1] = 1;
            }
            for (int i = 2; i <= n; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    for (int k = 1; k <= rollMax[j]; k++)
                    {
                        for (int p = 0; p < 6; p++)
                        {
                            if (p != j)
                            {
                                d[i][p][1] = (d[i][p][1] + d[i - 1][j][k]) % MOD;
                            }
                            else if (k + 1 <= rollMax[j])
                            {
                                d[i][p][k + 1] = (d[i][p][k + 1] + d[i - 1][j][k]) % MOD;
                            }
                        }
                    }
                }
            }

            int res = 0;
            for (int j = 0; j < 6; j++)
            {
                for (int k = 1; k <= rollMax[j]; k++)
                {
                    res = (res + d[n][j][k]) % MOD;
                }
            }
            return res;
        }

    }
}
