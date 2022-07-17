using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo565
{
    public class Class565
    {
        /// <summary>
        /// 方法一：图
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int ArrayNesting(int[] nums)
        {
            int ans = 0, n = nums.Length;
            bool[] vis = new bool[n];
            for (int i = 0; i < n; ++i)
            {
                int cnt = 0;
                while (!vis[i])
                {
                    vis[i] = true;
                    i = nums[i];
                    ++cnt;
                }
                ans = Math.Max(ans, cnt);
            }
            return ans;
        }


        /// <summary>
        /// 方法二：原地标记
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public int ArrayNesting2(int[] nums)
        {
            int ans = 0, n = nums.Length;
            for (int i = 0; i < n; ++i)
            {
                int cnt = 0;
                while (nums[i] < n)
                {
                    int num = nums[i];
                    nums[i] = n;
                    i = num;
                    ++cnt;
                }
                ans = Math.Max(ans, cnt);
            }
            return ans;
        }


    }
}
