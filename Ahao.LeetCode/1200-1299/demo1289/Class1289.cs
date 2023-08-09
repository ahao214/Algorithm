using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1289
{
    public class Class1289
    {
        /// <summary>
        /// 对负数有问题
        /// </summary>
        /// <param name="grid"></param>
        /// <returns></returns>
        public int MinFallingPathSum(int[][] grid)
        {
            int sum = 0;
            int n = grid.Length;
            int minFirst = int.MaxValue;
            int minSecond = int.MaxValue;
            int minIndex = -1;
            for (int i = 0; i < n; i++)
            {
                if (grid[0][i] < minFirst)
                {
                    minFirst = grid[0][i];
                    minIndex = i;
                }
            }

            sum = minFirst;

            for (int i = 1; i < n; i++)
            {
                int[] res = GetValue(grid, i);
                if (res[0] != minIndex)
                {
                    sum += res[1];
                    minIndex = res[0];
                }
                else
                {
                    sum += res[3];
                    minIndex = res[2];
                }
            }

            return sum;
        }


        public int[] GetValue(int[][] grid, int i)
        {
            int[] res = new int[4];
            int minFirst = int.MaxValue;
            int minSecond = int.MaxValue;
            int minFirstIndex = -1;
            int minSecondIndex = -1;
            for (int j = 0; j < grid.Length; j++)
            {
                if (grid[i][j] < minFirst)
                {
                    minFirst = grid[i][j];
                    minFirstIndex = j;
                }
            }
            for (int j = 0; j < grid.Length; j++)
            {
                if (grid[i][j] < minSecond && grid[i][j] != minFirst)
                {

                    minSecond = grid[i][j];
                    minSecondIndex = j;
                }
            }

            res[0] = minFirstIndex;
            res[1] = minFirst;
            res[2] = minSecondIndex;
            res[3] = minSecond;
            return res;
        }

    }
}
