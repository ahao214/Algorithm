﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1994
{
    public class Class1994
    {

        static int[] PRIMES = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        static int NUM_MAX = 30;
        static int MOD = 1000000007;

        public int NumberOfGoodSubsets(int[] nums)
        {
            int[] freq = new int[NUM_MAX + 1];
            foreach (int num in nums)
            {
                ++freq[num];
            }

            int[] f = new int[1 << PRIMES.Length];
            f[0] = 1;
            for (int i = 0; i < freq[1]; ++i)
            {
                f[0] = f[0] * 2 % MOD;
            }

            for (int i = 2; i <= NUM_MAX; ++i)
            {
                if (freq[i] == 0)
                {
                    continue;
                }

                // 检查 i 的每个质因数是否均不超过 1 个
                int subset = 0, x = i;
                bool check = true;
                for (int j = 0; j < PRIMES.Length; ++j)
                {
                    int prime = PRIMES[j];
                    if (x % (prime * prime) == 0)
                    {
                        check = false;
                        break;
                    }
                    if (x % prime == 0)
                    {
                        subset |= (1 << j);
                    }
                }
                if (!check)
                {
                    continue;
                }

                // 动态规划
                for (int mask = (1 << PRIMES.Length) - 1; mask > 0; --mask)
                {
                    if ((mask & subset) == subset)
                    {
                        f[mask] = (int)((f[mask] + ((long)f[mask ^ subset]) * freq[i]) % MOD);
                    }
                }
            }

            int ans = 0;
            for (int mask = 1, maskMax = (1 << PRIMES.Length); mask < maskMax; ++mask)
            {
                ans = (ans + f[mask]) % MOD;
            }

            return ans;
        }

    }
}
