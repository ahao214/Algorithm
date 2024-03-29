﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1402
{
    public class Class1402
    {
        public int MaxSatisfaction(int[] satisfaction)
        {
            int n = satisfaction.Length;
            int[][] dp = new int[n + 1][];
            for (int i = 0; i <= n; i++)
            {
                dp[i] = new int[n + 1];
            }
            Array.Sort(satisfaction);
            int res = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    dp[i][j] = dp[i - 1][j - 1] + satisfaction[i - 1] * j;
                    if (j < i)
                    {
                        dp[i][j] = Math.Max(dp[i - 1][j], dp[i][j]);
                    }
                    res = Math.Max(res, dp[i][j]);
                }
            }
            return res;
        }





        public int MaxSatisfaction2(int[] satisfaction)
        {
            Array.Sort(satisfaction, (a, b) => b - a);
            int presum = 0, ans = 0;
            foreach (int si in satisfaction)
            {
                if (presum + si > 0)
                {
                    presum += si;
                    ans += presum;
                }
                else
                {
                    break;
                }
            }
            return ans;
        }



        public int MaxSatisfaction3(int[] satisfaction)
        {
            Array.Sort(satisfaction);
            int sum = 0;
            int num = 0;
            for (int i = satisfaction.Length - 1; i >= 0; i--)
            {
                var cur = satisfaction[i];
                if (cur <= -num)
                {
                    break;
                }
                sum = sum + cur + num;
                num += cur;
            }
            return sum;
        }


        public int MaxSatisfaction4(int[] satisfaction)
        {
            Array.Sort(satisfaction);
            int result = 0, presum = 0;
            for (int i = satisfaction.Length - 1; i >= 0; i--)
            {
                presum += satisfaction[i];
                if (presum < 0)
                    break;
                else
                    result += presum;
            }

            return result;
        }


    }
}
