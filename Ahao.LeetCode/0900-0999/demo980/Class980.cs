using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo980
{
    public class Class980
    {

        static int[][] dirs = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };

        public int UniquePathsIII(int[][] grid)
        {
            int r = grid.Length, c = grid[0].Length;
            int si = 0, sj = 0, n = 0;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j] == 0)
                    {
                        n++;
                    }
                    else if (grid[i][j] == 1)
                    {
                        n++;
                        si = i;
                        sj = j;
                    }
                }
            }
            return DFS(grid, si, sj, n);
        }

        public int DFS(int[][] grid, int i, int j, int n)
        {
            if (grid[i][j] == 2)
            {
                return n == 0 ? 1 : 0;
            }
            int r = grid.Length, c = grid[0].Length;
            int t = grid[i][j];
            grid[i][j] = -1;
            int res = 0;
            foreach (int[] dir in dirs)
            {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && (grid[ni][nj] == 0 || grid[ni][nj] == 2))
                {
                    res += DFS(grid, ni, nj, n - 1);
                }
            }
            grid[i][j] = t;
            return res;
        }



        static int[][] dirs2 = { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };
        IDictionary<int, int> memo = new Dictionary<int, int>();

        public int UniquePathsIII2(int[][] grid)
        {
            int r = grid.Length, c = grid[0].Length;
            int si = 0, sj = 0, st = 0;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j] == 0 || grid[i][j] == 2)
                    {
                        st |= 1 << (i * c + j);
                    }
                    else if (grid[i][j] == 1)
                    {
                        si = i;
                        sj = j;
                    }
                }
            }
            return DP(grid, si, sj, st);
        }

        public int DP(int[][] grid, int i, int j, int st)
        {
            if (grid[i][j] == 2)
            {
                return st == 0 ? 1 : 0;
            }
            int r = grid.Length, c = grid[0].Length;
            int key = ((i * c + j) << (r * c)) + st;
            if (!memo.ContainsKey(key))
            {
                int res = 0;
                foreach (int[] dir in dirs)
                {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c && (st & (1 << (ni * c + nj))) > 0)
                    {
                        res += DP(grid, ni, nj, st ^ (1 << (ni * c + nj)));
                    }
                }
                memo.Add(key, res);
            }
            return memo[key];
        }


    }
}
