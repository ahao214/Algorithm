using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1267
{
    public class Class1267
    {
        public int CountServers(int[][] grid)
        {
            int res = 0;
            int m = grid.Length;
            int n = grid[0].Length;
            for (int i = 0; i < m; i++)
            {
                int sRow = SumRow(grid, i);
                for (int j = 0; j < n; j++)
                {
                    int sCol = SumCol(grid, j);
                    if (grid[i][j] == 1 && (sRow > 1 || sCol > 1))
                    {
                        res++;
                    }
                }
            }

            return res;
        }

        /// <summary>
        /// 求每一行的总和
        /// </summary>        
        /// <param name="row"></param>
        /// <returns></returns>
        public int SumRow(int[][] grid, int rowNo)
        {
            int res = 0; ;
            for (int i = 0; i < grid[0].Length; i++)
            {
                res += grid[rowNo][i];
            }
            return res;
        }

        /// <summary>
        /// 求每一列的总和
        /// </summary>
        /// <param name="grid"></param>        
        /// <param name="col"></param>
        /// <returns></returns>
        public int SumCol(int[][] grid, int colNo)
        {
            int res = 0;
            for (int i = 0; i < grid.Length; i++)
            {
                res += grid[i][colNo];
            }
            return res;
        }

    }
}
