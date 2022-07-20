using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1260
{
    public class Class1260
    {
        public IList<IList<int>> ShiftGrid(int[][] grid, int k)
        {
            int m = grid.Length, n = grid[0].Length;
            IList<IList<int>> res = new List<IList<int>>();

            for (int i = 0; i < m; i++)
            {
                IList<int> row = new List<int>();
                for (int j = 0; j < n; j++)
                {
                    row.Add(0);
                }
                res.Add(row);
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int index = (i * n + j + k) % (m * n);
                    res[index / n][index % n] = grid[i][j];
                }
            }

            return res;

        }
    }
}
