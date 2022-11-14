using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo805
{
    public class Class805
    {
        public bool SplitArraySameAverage(int[] nums)
        {
            if (nums.Length == 1)
            {
                return false;
            }
            int n = nums.Length, m = n / 2;
            int sum = 0;
            foreach (int num in nums)
            {
                sum += num;
            }
            for (int i = 0; i < n; i++)
            {
                nums[i] = nums[i] * n - sum;
            }

            ISet<int> left = new HashSet<int>();
            for (int i = 1; i < (1 << m); i++)
            {
                int tot = 0;
                for (int j = 0; j < m; j++)
                {
                    if ((i & (1 << j)) != 0)
                    {
                        tot += nums[j];
                    }
                }
                if (tot == 0)
                {
                    return true;
                }
                left.Add(tot);
            }
            int rsum = 0;
            for (int i = m; i < n; i++)
            {
                rsum += nums[i];
            }
            for (int i = 1; i < (1 << (n - m)); i++)
            {
                int tot = 0;
                for (int j = m; j < n; j++)
                {
                    if ((i & (1 << (j - m))) != 0)
                    {
                        tot += nums[j];
                    }
                }
                if (tot == 0 || (rsum != tot && left.Contains(-tot)))
                {
                    return true;
                }
            }
            return false;
        }


        /// <summary>
        /// 动态规划
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public bool SplitArraySameAverage2(int[] nums)
        {
            if (nums.Length == 1)
            {
                return false;
            }
            int n = nums.Length, m = n / 2;
            int sum = 0;
            foreach (int num in nums)
            {
                sum += num;
            }
            bool isPossible = false;
            for (int i = 1; i <= m; i++)
            {
                if (sum * i % n == 0)
                {
                    isPossible = true;
                    break;
                }
            }
            if (!isPossible)
            {
                return false;
            }
            ISet<int>[] dp = new ISet<int>[m + 1];
            for (int i = 0; i <= m; i++)
            {
                dp[i] = new HashSet<int>();
            }
            dp[0].Add(0);
            foreach (int num in nums)
            {
                for (int i = m; i >= 1; i--)
                {
                    foreach (int x in dp[i - 1])
                    {
                        int curr = x + num;
                        if (curr * n == sum * i)
                        {
                            return true;
                        }
                        dp[i].Add(curr);
                    }
                }
            }
            return false;
        }

    }
}
