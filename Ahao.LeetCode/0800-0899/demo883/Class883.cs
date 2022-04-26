using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo883
{
    public class Class883
    {
        public int ProjectionArea(int[][] grid)
        {
            int n = grid.Length;
            int xyArea = 0, yzArea = 0, zxArea = 0;
            for (int i = 0; i < n; i++)
            {
                int yzHeight = 0, zxHeight = 0;
                for (int j = 0; j < n; j++)
                {
                    xyArea += grid[i][j] > 0 ? 1 : 0;
                    yzHeight = Math.Max(yzHeight, grid[i][j]);
                    zxHeight = Math.Max(zxHeight, grid[j][i]);
                }
                yzArea += yzHeight;
                zxArea += zxHeight;
            }
            return xyArea + yzArea + zxArea;
        }
    }
}
