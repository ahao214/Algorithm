using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo204
{
    public class Class204
    {
        public int CountPrimes(int n)
        {
            if (n < 3)
                return 0;
            bool[] f = new bool[n];
            //所有偶数都不要
            int count = n / 2;
            for (int i = 3; i * i < n; i += 2)
            {
                if (f[i])
                    continue;
                for (int j = i * i; j < n; j += 2 * i)
                {
                    if (!f[j])
                    {
                        --count;
                        f[j] = true;
                    }
                }
            }
            return count;
        }
    }
}
