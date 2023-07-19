﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo874
{
    internal class Class874
    {
        public int RobotSim(int[] commands, int[][] obstacles)
        {
            int[][] dirs = { new int[] { -1, 0 }, new int[] { 0, 1 }, new int[] { 1, 0 }, new int[] { 0, -1 } };
            int px = 0, py = 0, d = 1;
            ISet<int> set = new HashSet<int>();
            foreach (int[] obstacle in obstacles)
            {
                set.Add(obstacle[0] * 60001 + obstacle[1]);
            }
            int res = 0;
            foreach (int c in commands)
            {
                if (c < 0)
                {
                    d += c == -1 ? 1 : -1;
                    d %= 4;
                    if (d < 0)
                    {
                        d += 4;
                    }
                }
                else
                {
                    for (int i = 0; i < c; i++)
                    {
                        if (set.Contains((px + dirs[d][0]) * 60001 + py + dirs[d][1]))
                        {
                            break;
                        }
                        px += dirs[d][0];
                        py += dirs[d][1];
                        res = Math.Max(res, px * px + py * py);
                    }
                }
            }
            return res;
        }
    }
}
