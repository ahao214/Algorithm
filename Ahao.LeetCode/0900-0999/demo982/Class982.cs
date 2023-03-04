using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo982
{
    public class Class982
    {
        public int CountTriplets(int[] nums)
        {
            int res = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if ((nums[i] & nums[j] & nums[k]) == 0)
                            res++;
                    }
                }
            }
            return res;
        }


        /// <summary>
        /// 枚举
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int CountTriplets2(int[] nums)
        {
            int[] cnt = new int[1 << 16];
            foreach (int x in nums)
            {
                foreach (int y in nums)
                {
                    ++cnt[x & y];
                }
            }
            int ans = 0;
            foreach (int x in nums)
            {
                for (int mask = 0; mask < (1 << 16); ++mask)
                {
                    if ((x & mask) == 0)
                    {
                        ans += cnt[mask];
                    }
                }
            }
            return ans;
        }


        /// <summary>
        /// 枚举 + 子集优化
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int CountTriplets3(int[] nums)
        {
            int[] cnt = new int[1 << 16];
            foreach (int x in nums)
            {
                foreach (int y in nums)
                {
                    ++cnt[x & y];
                }
            }
            int ans = 0;
            foreach (int x in nums)
            {
                int y = x ^ 0xffff;
                for (int sub = y; sub != 0; sub = (sub - 1) & y)
                {
                    ans += cnt[sub];
                }
                ans += cnt[0];
            }
            return ans;
        }


    }
}
