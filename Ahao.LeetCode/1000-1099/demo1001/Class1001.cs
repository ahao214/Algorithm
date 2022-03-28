﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1001
{
    public class Class1001
    {
        public int[] GridIllumination(int n, int[][] lamps, int[][] queries)
        {
            Dictionary<int, int> row = new Dictionary<int, int>();
            Dictionary<int, int> col = new Dictionary<int, int>();
            Dictionary<int, int> diagonal = new Dictionary<int, int>();
            Dictionary<int, int> antiDiagonal = new Dictionary<int, int>();
            ISet<long> points = new HashSet<long>();
            foreach (int[] lamp in lamps)
            {
                if (!points.Add(Hash(lamp[0], lamp[1])))
                {
                    continue;
                }
                if (!row.ContainsKey(lamp[0]))
                {
                    row.Add(lamp[0], 0);
                }
                row[lamp[0]]++;
                if (!col.ContainsKey(lamp[1]))
                {
                    col.Add(lamp[1], 0);
                }
                col[lamp[1]]++;
                if (!diagonal.ContainsKey(lamp[0] - lamp[1]))
                {
                    diagonal.Add(lamp[0] - lamp[1], 0);
                }
                diagonal[lamp[0] - lamp[1]]++;
                if (!antiDiagonal.ContainsKey(lamp[0] + lamp[1]))
                {
                    antiDiagonal.Add(lamp[0] + lamp[1], 0);
                }
                antiDiagonal[lamp[0] + lamp[1]]++;
            }
            int[] ret = new int[queries.Length];
            for (int i = 0; i < queries.Length; i++)
            {
                int r = queries[i][0], c = queries[i][1];
                if (row.ContainsKey(r) && row[r] > 0)
                {
                    ret[i] = 1;
                }
                else if (col.ContainsKey(c) && col[c] > 0)
                {
                    ret[i] = 1;
                }
                else if (diagonal.ContainsKey(r - c) && diagonal[r - c] > 0)
                {
                    ret[i] = 1;
                }
                else if (antiDiagonal.ContainsKey(r + c) && antiDiagonal[r + c] > 0)
                {
                    ret[i] = 1;
                }
                for (int x = r - 1; x <= r + 1; x++)
                {
                    for (int y = c - 1; y <= c + 1; y++)
                    {
                        if (x < 0 || y < 0 || x >= n || y >= n)
                        {
                            continue;
                        }
                        if (points.Remove(Hash(x, y)))
                        {
                            row[x]--;
                            if (row[x] == 0)
                            {
                                row.Remove(x);
                            }
                            col[y]--;
                            if (col[y] == 0)
                            {
                                col.Remove(y);
                            }
                            diagonal[x - y]--;
                            if (diagonal[x - y] == 0)
                            {
                                diagonal.Remove(x - y);
                            }
                            antiDiagonal[x + y]--;
                            if (antiDiagonal[x + y] == 0)
                            {
                                antiDiagonal.Remove(x + y);
                            }
                        }
                    }
                }
            }
            return ret;
        }

        public long Hash(int x, int y)
        {
            return (long)x + ((long)y << 32);
        }
    }
}

