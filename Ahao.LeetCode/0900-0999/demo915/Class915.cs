using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo915
{
    public class Class915
    {
        public int PartitionDisjoint(int[] nums)
        {
            int res = 0, maxValue = nums[0], maxValue1 = nums[0];
            for (int i = 0; i < nums.Length; i++)
            {
                int num = nums[i];
                if (maxValue > num)
                {
                    res = i;
                    maxValue = maxValue1;
                }
                maxValue1 = Math.Max(num, maxValue1);
            }
            return res + 1;
        }


        public int PartitionDisjoint2(int[] nums)
        {
            int n = nums.Length;
            int[] minRight = new int[n];
            minRight[n - 1] = nums[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                minRight[i] = Math.Min(nums[i], minRight[i + 1]);
            }

            int maxLeft = 0;
            for (int i = 0; i < n - 1; i++)
            {
                maxLeft = Math.Max(maxLeft, nums[i]);
                if (maxLeft <= minRight[i + 1])
                {
                    return i + 1;
                }
            }
            return n - 1;
        }
    }
}
