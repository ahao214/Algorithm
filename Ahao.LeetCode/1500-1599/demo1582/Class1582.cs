using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1500_1599.demo1582
{
    public class Class1582
    {
        //方法一：模拟
        public int NumSpecial(int[][] mat)
        {
            int m = mat.Length, n = mat[0].Length;
            int[] rowsSum = new int[m];
            int[] colsSum = new int[n];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    rowsSum[i] += mat[i][j];
                    colsSum[j] += mat[i][j];
                }
            }
            int res = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1)
                    {
                        res++;
                    }
                }
            }
            return res;
        }

        //方法二：列的标记值
        public int NumSpecial2(int[][] mat)
        {
            int m = mat.Length, n = mat[0].Length;
            for (int i = 0; i < m; i++)
            {
                int cnt1 = 0;
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][j] == 1)
                    {
                        cnt1++;
                    }
                }
                if (i == 0)
                {
                    cnt1--;
                }
                if (cnt1 > 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (mat[i][j] == 1)
                        {
                            mat[0][j] += cnt1;
                        }
                    }
                }
            }
            int sum = 0;
            foreach (int num in mat[0])
            {
                if (num == 1)
                {
                    sum++;
                }
            }
            return sum;
        }


    }
}
