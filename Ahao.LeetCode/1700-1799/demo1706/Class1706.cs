using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1706
{
    public class Class1706
    {
        public int[] FindBall(int[][] grid)
        {
            int n = grid[0].Length;
            int[] ans = new int[n];
            Array.Fill(ans, -1);
            for (int j = 0; j < n; j++)
            {
                int col = j;
                foreach (int[] row in grid)
                {
                    int dir = row[col];
                    col += dir;
                    if (col < 0 || col == n || row[col] != dir)
                    {
                        col -= 1;
                        break;
                    }
                }
                if (col >= 0)
                {
                    ans[j] = col;
                }
            }
            return ans;
        }
    }
}
