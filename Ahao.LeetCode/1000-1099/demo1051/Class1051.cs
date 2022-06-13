using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1051
{
    public class Class1051
    {
        /// <summary>
        /// 基于比较的排序
        /// </summary>
        /// <param name="heights"></param>
        /// <returns></returns>
        public int HeightChecker(int[] heights)
        {
            int n = heights.Length, ans = 0;
            int[] expected = new int[n];
            Array.Copy(heights, 0, expected, 0, n);
            Array.Sort(expected);
            for (int i = 0; i < n; ++i)
            {
                if (heights[i] != expected[i])
                {
                    ++ans;
                }
            }
            return ans;
        }


        /// <summary>
        /// 计数排序
        /// </summary>
        /// <param name="heights"></param>
        /// <returns></returns>
        public int HeightChecker2(int[] heights)
        {
            int m = heights.Max();
            int[] cnt = new int[m + 1];
            foreach (int h in heights)
            {
                ++cnt[h];
            }

            int idx = 0, ans = 0;
            for (int i = 1; i <= m; ++i)
            {
                for (int j = 1; j <= cnt[i]; ++j)
                {
                    if (heights[idx] != i)
                    {
                        ++ans;
                    }
                    ++idx;
                }
            }
            return ans;
        }

    }
}
