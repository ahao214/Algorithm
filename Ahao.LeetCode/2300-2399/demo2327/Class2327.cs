using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2327
{
    public class Class2327
    {
        public int PeopleAwareOfSecret(int n, int delay, int forget)
        {
            long mod = 1000000007;
            //知道秘密的人
            long[] dpKnow = new long[n + 1];
            //忘记秘密的人
            long[] dpForget = new long[n + 1];
            //分享秘密的人
            long[] dpShare = new long[n + 1];

            dpKnow[1] = 1;
            if (1 + forget <= n)
            {
                dpForget[1 + forget] = 1;
            }

            if (1 + delay <= n)
            {
                dpShare[1 + delay] = 1;
            }

            for (int i = 2; i <= n; i++)
            {
                dpKnow[i] = (mod + dpKnow[i - 1] - dpForget[i] + dpShare[i]) % mod;
                if (i + forget <= n)
                {
                    dpForget[i + forget] = dpShare[i];
                }

                if (i + delay <= n)
                {
                    dpShare[i + delay] = (mod + dpShare[i + delay - 1] - dpForget[i + delay] + dpShare[i]) % mod;
                }
            }
            return (int)dpKnow[n];
        }

    }
}
