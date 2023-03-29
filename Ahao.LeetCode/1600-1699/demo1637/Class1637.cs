using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1637
{
    public class Class1637
    {
        public int MaxWidthOfVerticalArea(int[][] points)
        {
            int res = 0;
            Array.Sort(points, (a, b) => a[0] - b[0]);
            for (int i = 1; i < points.Length; i++)
            {
                res = Math.Max(res, points[i][0] - points[i - 1][0]);
            }
            return res;
        }
    }
}
