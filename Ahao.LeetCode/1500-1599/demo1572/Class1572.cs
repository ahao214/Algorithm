using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1500_1599.demo1572
{
    public class Class1572
    {
        public int DiagonalSum(int[][] mat)
        {
            int res = 0;
            int n = mat.Length;
            int primaryDia = 0;
            int secondaryDia = 0;
            for (int i = 0; i < n; i++)
            {
                primaryDia += mat[i][i];
                secondaryDia += mat[i][n - i - 1];
            }
            if (n % 2 == 0)
            {
                res = primaryDia + secondaryDia;
            }
            else
            {
                res = primaryDia + secondaryDia - mat[n / 2][n / 2];
            }

            return res;
        }

    }
}
