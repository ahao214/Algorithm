using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2319
{
    public class Class2319
    {

        public bool CheckXMatrix(int[][] grid)
        {
            int n = grid.Length;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i == j || (i + j) == (n - 1))
                    {
                        if (grid[i][j] == 0)
                        {
                            return false;
                        }
                    }
                    else if (grid[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

    }
}
