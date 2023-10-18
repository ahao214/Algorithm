using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Ahao.LeetCode._2500_2599.demo2530
{
    public class Class2530
    {

        public long MaxKelements(int[] nums, int k)
        {
            long res = 0;
            int count = 0, n = nums.Length;
            while (count < k)
            {
                Array.Sort(nums);
                int i = n - 1, min = (nums[n - 1] + 2) / 3;
                while (i >= 0 && count < k && nums[i] >= min)
                {
                    res += nums[i--];
                    count++;
                }
                if (count == k) break;
                while (++i < n) nums[i] = (nums[i] + 2) / 3;
            }
            return res;
        }


    }
}
