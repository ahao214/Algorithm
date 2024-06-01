using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2900_2999._2928
{
    internal class Class2928
    {

        public int DistributeCandies(int n, int limit)
        {
            int ans = 0;
            for (int i = 0; i <= limit; i++)
            {
                for (int j = 0; j <= limit; j++)
                {
                    if (i + j > n)
                    {
                        break;
                    }
                    if (n - i - j <= limit)
                    {
                        ans++;
                    }
                }
            }
            return ans;
        }


        public int DistributeCandies2(int n, int limit)
        {
            int ans = 0;
            for (int i = 0; i <= Math.Min(limit, n); i++)
            {
                if (n - i > 2 * limit)
                {
                    continue;
                }
                ans += Math.Min(n - i, limit) - Math.Max(0, n - i - limit) + 1;
            }
            return ans;
        }


        public int DistributeCandies3(int n, int limit)
        {
            return Cal(n + 2) - 3 * Cal(n - limit + 1) + 3 * Cal(n - (limit + 1) * 2 + 2) - Cal(n - 3 * (limit + 1) + 2);
        }

        public int Cal(int x)
        {
            return x < 0 ? 0 : x * (x - 1) / 2;
        }


    }
}
