using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo447
{
    public class Class447
    {

        public int NumberOfBoomerangs(int[][] points)
        {
            int ans = 0;
            foreach (int[] p in points)
            {
                Dictionary<int, int> cnt = new Dictionary<int, int>();
                foreach (int[] q in points)
                {
                    int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                    if (!cnt.ContainsKey(dis))
                    {
                        cnt.Add(dis, 1);
                    }
                    else
                    {
                        ++cnt[dis];
                    }
                }
                foreach (KeyValuePair<int, int> kv in cnt)
                {
                    int m = kv.Value;
                    ans += m * (m - 1);
                }
            }
            return ans;
        }

    }
}
