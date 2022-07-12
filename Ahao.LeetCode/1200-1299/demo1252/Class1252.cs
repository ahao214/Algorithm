using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1252
{
    public class Class1252
    {

        /// <summary>
        /// 直接模拟
        /// </summary>
        /// <param name="m"></param>
        /// <param name="n"></param>
        /// <param name="indices"></param>
        /// <returns></returns>
        public int OddCells(int m, int n, int[][] indices)
        {
            int res = 0;
            int[,] matrix = new int[m, n];
            foreach (int[] index in indices)
            {
                for (int i = 0; i < n; i++)
                {
                    matrix[index[0], i]++;
                }
                for (int i = 0; i < m; i++)
                {
                    matrix[i, index[1]]++;
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((matrix[i, j] & 1) != 0)
                    {
                        res++;
                    }
                }
            }
            return res;
        }


        /// <summary>
        /// 方法二：模拟空间优化
        /// </summary>
        /// <param name="m"></param>
        /// <param name="n"></param>
        /// <param name="indices"></param>
        /// <returns></returns>

        public int OddCells2(int m, int n, int[][] indices)
        {
            int[] rows = new int[m];
            int[] cols = new int[n];
            foreach (int[] index in indices)
            {
                rows[index[0]]++;
                cols[index[1]]++;
            }
            int res = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (((rows[i] + cols[j]) & 1) != 0)
                    {
                        res++;
                    }
                }
            }
            return res;
        }

        /// <summary>
        /// 方法三：计数优化
        /// </summary>
        /// <param name="m"></param>
        /// <param name="n"></param>
        /// <param name="indices"></param>
        /// <returns></returns>
        public int OddCells3(int m, int n, int[][] indices)
        {
            int[] rows = new int[m];
            int[] cols = new int[n];
            foreach (int[] index in indices)
            {
                rows[index[0]]++;
                cols[index[1]]++;
            }
            int oddx = 0, oddy = 0;
            for (int i = 0; i < m; i++)
            {
                if ((rows[i] & 1) != 0)
                {
                    oddx++;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if ((cols[i] & 1) != 0)
                {
                    oddy++;
                }
            }
            return oddx * (n - oddy) + (m - oddx) * oddy;
        }


    }
}
