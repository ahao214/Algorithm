using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1779
{
    public class Class1779
    {
        public int NearestValidPoint(int x, int y, int[][] points)
        {
            int n = points.Length;
            int best = int.MaxValue, bestid = -1;
            for (int i = 0; i < n; ++i)
            {
                int px = points[i][0], py = points[i][1];
                if (x == px)
                {
                    int dist = Math.Abs(y - py);
                    if (dist < best)
                    {
                        best = dist;
                        bestid = i;
                    }
                }
                else if (y == py)
                {
                    int dist = Math.Abs(x - px);
                    if (dist < best)
                    {
                        best = dist;
                        bestid = i;
                    }
                }
            }
            return bestid;
        }
    }
}
