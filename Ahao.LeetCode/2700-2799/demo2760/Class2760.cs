using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2700_2799.demo2760
{
    public class Class2760
    {
        public int LongestAlternatingSubarray(int[] nums, int threshold)
        {
            int res = 0, n = nums.Length;
            for (int l = 0; l < n; l++)
            {
                for (int r = l; r < n; r++)
                {
                    if (IsSatisfied(nums, l, r, threshold))
                    {
                        res = Math.Max(res, r - l + 1);
                    }
                }
            }
            return res;
        }

        public bool IsSatisfied(int[] nums, int l, int r, int threshold)
        {
            if (nums[l] % 2 != 0)
            {
                return false;
            }
            for (int i = l; i <= r; i++)
            {
                if (nums[i] > threshold || (i < r && nums[i] % 2 == nums[i + 1] % 2))
                {
                    return false;
                }
            }
            return true;
        }



        public int LongestAlternatingSubarray2(int[] nums, int threshold)
        {
            int res = 0, dp = 0;
            for (int l = nums.Length - 1; l >= 0; l--)
            {
                if (nums[l] > threshold)
                {
                    dp = 0;
                }
                else if (l == nums.Length - 1 || nums[l] % 2 != nums[l + 1] % 2)
                {
                    dp++;
                }
                else
                {
                    dp = 1;
                }
                if (nums[l] % 2 == 0)
                {
                    res = Math.Max(res, dp);
                }
            }
            return res;
        }

        public int longestAlternatingSubarray(int[] nums, int threshold)
        {
            int res = 0;
            int start = -1;
            for (int i = 0; i < nums.Length; i++)
            {
                if (start != -1 && nums[i] % 2 != nums[i - 1] % 2 && nums[i] <= threshold)
                {
                    res = Math.Max(res, i - start + 1);
                }
                else if (nums[i] % 2 == 0 && nums[i] <= threshold)
                {
                    start = i;
                    res = Math.Max(res, 1);
                }
                else
                {
                    start = -1;
                }
            }
            return res;
        }


    }
}
