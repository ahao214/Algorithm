using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2779
{
    internal class Class2779
    {

        public int MaximumBeauty(int[] nums, int k)
        {
            int res = 0;
            int n = nums.Length;
            Array.Sort(nums);
            for (int i = 0, j = 0; i < n; i++)
            {
                while (nums[i] - 2 * k > nums[j])
                {
                    j++;
                }
                res = Math.Max(res, i = j + 1);
            }
            return res;
        }


        public int MaximumBeauty2(int[] nums, int k)
        {
            int m = 0;
            foreach (int x in nums)
            {
                m = Math.Max(m, x);
            }
            int[] diff = new int[m + 2];
            foreach (int x in nums)
            {
                diff[Math.Max(x - k, 0)]++;
                diff[Math.Min(x + k + 1, m + 1)]--;
            }
            int res = 0, count = 0;
            foreach (int x in diff)
            {
                count += x;
                res = Math.Max(res, count);
            }
            return res;
        }

    }
}
