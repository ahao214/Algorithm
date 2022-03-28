using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo807
{
    public class Class807
    {
        public int MaxIncreaseKeepingSkyline(int[][] grid)
        {
            int n = grid.Length;
            //记录每行的最大值
            int[] rowMax = new int[n];
            //记录每列的最大值
            int[] colMax = new int[n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    rowMax[i] = Math.Max(rowMax[i], grid[i][j]);
                    colMax[j] = Math.Max(colMax[j], grid[i][j]);
                }
            }

            int res = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    //每个建筑物所能增加的高度
                    res += Math.Min(rowMax[i], colMax[j]) - grid[i][j];
                }
            }
            return res;
        }
    }
}
