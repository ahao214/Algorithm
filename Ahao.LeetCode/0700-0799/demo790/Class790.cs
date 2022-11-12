using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo790
{
    public class Class790
    {

        const int MOD = 1000000007;
        /// <summary>
        /// 动态规划
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int NumTilings(int n)
        {
            int[][] dp = new int[n + 1][];
            for (int i = 0; i <= n; i++)
            {
                dp[i] = new int[4];
            }
            dp[0][3] = 1;
            for (int i = 1; i <= n; i++)
            {
                dp[i][0] = dp[i - 1][3];
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
                dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                dp[i][3] = (((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD + dp[i - 1][3]) % MOD;
            }
            return dp[n][3];
        }



        //const int MOD = 1000000007;
        /// <summary>
        /// 矩阵快速幂
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int NumTilings2(int n)
        {
            int[][] mat = {
            new int[]{0, 0, 0, 1},
            new int[]{1, 0, 1, 0},
            new int[]{1, 1, 0, 0},
            new int[]{1, 1, 1, 1}
        };
            int[][] matn = {
            new int[]{1, 0, 0, 0},
            new int[]{0, 1, 0, 0},
            new int[]{0, 0, 1, 0},
            new int[]{0, 0, 0, 1}
        };
            while (n > 0)
            {
                if ((n & 1) != 0)
                {
                    matn = MulMatrix(matn, mat);
                }
                mat = MulMatrix(mat, mat);
                n >>= 1;
            }
            return matn[3][3];
        }

        public int[][] MulMatrix(int[][] m1, int[][] m2)
        {
            int n1 = m1.Length, n2 = m2.Length, n3 = m2[0].Length;
            int[][] res = new int[n1][];
            for (int i = 0; i < n1; i++)
            {
                res[i] = new int[n3];
                for (int k = 0; k < n3; k++)
                {
                    for (int j = 0; j < n2; j++)
                    {
                        res[i][k] = (int)((res[i][k] + (long)m1[i][j] * m2[j][k]) % MOD);
                    }
                }
            }
            return res;
        }


    }
}
