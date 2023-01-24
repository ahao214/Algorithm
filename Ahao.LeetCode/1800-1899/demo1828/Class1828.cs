using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1828
{
    public class Class1828
    {

        public int[] CountPoints(int[][] points, int[][] queries)
        {
            int m = points.Length, n = queries.Length;
            int[] ans = new int[n];
            for (int i = 0; i < n; ++i)
            {
                int cx = queries[i][0], cy = queries[i][1], cr = queries[i][2];
                for (int j = 0; j < m; ++j)
                {
                    int px = points[j][0], py = points[j][1];
                    if ((cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr)
                    {
                        ++ans[i];
                    }
                }
            }
            return ans;
        }
    }
}
