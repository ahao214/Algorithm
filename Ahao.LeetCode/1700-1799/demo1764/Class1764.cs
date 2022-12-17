using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1764
{
    public class Class1764
    {
        /// <summary>
        /// 贪心+双指针
        /// </summary>
        /// <param name="groups"></param>
        /// <param name="nums"></param>
        /// <returns></returns>
        public bool CanChoose(int[][] groups, int[] nums)
        {
            int i = 0;
            for (int k = 0; k < nums.Length && i < groups.Length;)
            {
                if (Check(groups[i], nums, k))
                {
                    k += groups[i].Length;
                    i++;
                }
                else
                {
                    k++;
                }
            }
            return i == groups.Length;
        }

        public bool Check(int[] g, int[] nums, int k)
        {
            if (k + g.Length > nums.Length)
            {
                return false;
            }
            for (int j = 0; j < g.Length; j++)
            {
                if (g[j] != nums[k + j])
                {
                    return false;
                }
            }
            return true;
        }



        /// <summary>
        /// KMP 匹配算法
        /// </summary>
        /// <param name="groups"></param>
        /// <param name="nums"></param>
        /// <returns></returns>
        public bool CanChoose2(int[][] groups, int[] nums)
        {
            int k = 0;
            for (int i = 0; i < groups.Length; i++)
            {
                k = Find(nums, k, groups[i]);
                if (k == -1)
                {
                    return false;
                }
                k += groups[i].Length;
            }
            return true;
        }

        public int Find(int[] nums, int k, int[] g)
        {
            int m = g.Length, n = nums.Length;
            if (k + g.Length > nums.Length)
            {
                return -1;
            }
            int[] pi = new int[m];
            for (int i = 1, j = 0; i < m; i++)
            {
                while (j > 0 && g[i] != g[j])
                {
                    j = pi[j - 1];
                }
                if (g[i] == g[j])
                {
                    j++;
                }
                pi[i] = j;
            }
            for (int i = k, j = 0; i < n; i++)
            {
                while (j > 0 && nums[i] != g[j])
                {
                    j = pi[j - 1];
                }
                if (nums[i] == g[j])
                {
                    j++;
                }
                if (j == m)
                {
                    return i - m + 1;
                }
            }
            return -1;
        }
    }
}
