﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo823
{
    public class Class823
    {
        public int NumFactoredBinaryTrees(int[] arr)
        {
            Array.Sort(arr);
            int n = arr.Length;
            long[] dp = new long[n];
            long res = 0, mod = 1000000007;
            for (int i = 0; i < n; i++)
            {
                dp[i] = 1;
                for (int left = 0, right = i - 1; left <= right; left++)
                {
                    while (right >= left && (long)arr[left] * arr[right] > arr[i])
                    {
                        right--;
                    }
                    if (right >= left && (long)arr[left] * arr[right] == arr[i])
                    {
                        if (right != left)
                        {
                            dp[i] = (dp[i] + dp[left] * dp[right] * 2) % mod;
                        }
                        else
                        {
                            dp[i] = (dp[i] + dp[left] * dp[right]) % mod;
                        }
                    }
                }
                res = (res + dp[i]) % mod;
            }
            return (int)res;
        }

    }
}
