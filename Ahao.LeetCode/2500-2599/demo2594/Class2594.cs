using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2594
{
    public  class Class2594
    {
            public long RepairCars(int[] ranks, int cars)
            {
                long l = 1, r = 1l * ranks[0] * cars * cars;
                while (l < r)
                {
                    long m = l + r >> 1;
                    if (Check(ranks, cars, m))
                    {
                        r = m;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
                return l;
            }

            public bool Check(int[] ranks, int cars, long m)
            {
                long cnt = 0;
                foreach (int x in ranks)
                {
                    cnt += (long)Math.Sqrt(m / x);
                }
                return cnt >= cars;
            }
        

    }
}
