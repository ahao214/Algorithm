using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2432
{
    public class Class2432
    {
        public int HardestWorker(int n, int[][] logs)
        {
            int maxCost = logs[0][1];
            int res = logs[0][0];
            for (int i = 1; i < logs.Length; i++)
            {
                int cost = logs[i][1] - logs[i - 1][1];
                int idx = logs[i][0];
                if (cost > maxCost || (cost == maxCost && idx < res))
                {
                    res = idx;
                    maxCost = cost;
                }
            }
            return res;

        }

    }
}
